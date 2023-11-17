#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Types.h"
#include <webgpu/webgpu.h>
#include <glfw3webgpu.h>
#include <unordered_map>
//#include "glm/glm.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <typeindex>

using namespace std;
namespace GameEng {

    

class ECS{
	public:
		typedef long EntityID;
        EntityID Create();
        //std::unordered_map< EntityID, Position > posEnt;
        //std::unordered_map< EntityID, Velocity > velEnt;
        //std::unordered_map< EntityID, Gravity > graEnt;
        //std::unordered_map< EntityID, Sprite > sprEnt;
        //std::unordered_map< EntityID, Script > scrEnt;

        template< typename T >
        std::unordered_map< EntityID, T >&
            GetAppropriateSparseSet() {
            // Get the index for T's SparseSet
            const ComponentIndex index = std::type_index(typeid(T));
            // Create the actual sparse set if needed.
            if (m_components[index] == nullptr) m_components[index] = std::make_unique< SparseSet<T> >();
            // It's safe to cast the SparseSetHolder to its subclass and return the std::unordered_map< EntityID, T > inside.
            return static_cast<SparseSet<T>&>(*m_components[index]).data;
        }

		template< typename T >
		T& Get( EntityID entity ) {
    		return GetAppropriateSparseSet<T>()[ entity ];
		}

        class SparseSetHolder {
        public:
            // A virtual destructor, since subclasses need their destructors to run to free memory.
            virtual ~SparseSetHolder() = default;
            virtual bool Has(EntityID) const = 0;
            virtual void Drop(EntityID) = 0;
        };
        // Subclasses are templated on the component type they hold.
        template< typename T > class SparseSet : public SparseSetHolder {
        public:
            std::unordered_map< EntityID, T > data;
            bool Has(EntityID e) const override { return data.count(e) > 0; };
            void Drop(EntityID e) override { data.erase(e); };
        };

        typedef std::type_index ComponentIndex;
        std::unordered_map< ComponentIndex, std::unique_ptr< SparseSetHolder > > m_components;

        // Drop a component from an entity.
        template< typename T >
        void Drop(EntityID e) {
            GetAppropriateSparseSet<T>().erase(e);
        }

        // Destroy the entity by removing all components.
        void Destroy(EntityID e) {
            for (const auto& [index, comps] : m_components) { comps->Drop(e); }
        }

        typedef std::function<void(EntityID)> ForEachCallback;
        template<typename EntitiesThatHaveThisComponent, typename... AndAlsoTheseComponents>
        void ForEach(const ForEachCallback& callback) {
            // Get a vector of ComponentIndex we can use with `m_components[ index ]->Has( entity )`.
            std::vector<ComponentIndex> also{ std::type_index(typeid(AndAlsoTheseComponents))... };
            //int count = 0;
            bool hasAll = true;
            //std::cout << "Does this run twice? " << count << endl;
            for (auto d : GetAppropriateSparseSet<EntitiesThatHaveThisComponent>())
            {
                //std::cout << "EntityIDs: " << d.first << endl;
                for (int i = 0; i < also.size(); i++)
                {
                    //std::cout << "Structs: " << m_components[also[i]]->Has(d.first) << endl;
                    if (m_components[also[i]] != nullptr)
                    {
                        //std::cout << "HAS ANOTHER COMPONENT!" << d.first << endl;
                        if (!m_components[also[i]]->Has(d.first))
                        {
                            hasAll = false;
                        }
                    }

                }
                if (hasAll)
                {
                    callback(d.first);
                }
                //count++;

                //std::cout << "Entities: " << d.x << endl;
                //std::cout << "Entities: " << d << endl;
                //for (int i = 0; i < m_components.size(); i++)
                //{
                    //if (m_components[also]->Has(d))
                    //{
                    //    count++;
                    //}
                //}
                //if (count == m_components.size())
                //{
                //    callback(d);
                //}
            }
            
            // Iterate over entities in the first container.
            // If the entity has all components in `also`, call `callback( entity )`.
            // ... your code goes here ...
        }
};
inline ECS globalECS;
}