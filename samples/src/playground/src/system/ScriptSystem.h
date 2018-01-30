
#pragma once

#include "ecs/Include.h"
#include "component/Include.h"
#include "system/Events.h"
#include "Wren++.h"
#include <unordered_map>
#include <set>
#include <cstdlib>
#include <cstdint>

namespace pg {

struct Context;
class KeyboardManager;
class MouseEvents;

namespace system {

class ScriptSystem : public ecs::System, public ecs::Receiver {
public:
    ScriptSystem(Context& context, KeyboardManager&, MouseEvents&);
    void configure(ecs::EventManager&) override;
    void update(ecs::EntityManager&, ecs::EventManager&, float) override;

    void receive(const ecs::ComponentAssignedEvent< component::Script >&);
    void receive(const ecs::ComponentRemovedEvent< component::Script >&);
    void receive(const system::TextFileUpdated&);

    void onKeyDown(const char*, ecs::Entity*);
    void onKeyPressed(const char*, ecs::Entity*);
    void onKeyUp(const char*, ecs::Entity*);
    void onMouseDown(const char*, ecs::Entity*);
    void onMousePressed(const char*, ecs::Entity*);
    void onMouseUp(const char*, ecs::Entity*);
    void onMouseScroll(std::int32_t dx, std::int32_t y, ecs::Entity*);
    void listenToKeyDown(std::string, ecs::Entity*);
    void listenToKeyPressed(std::string, ecs::Entity*);
    void listenToKeyUp(std::string, ecs::Entity*);
    void listenToMouseDown(std::string, ecs::Entity*);
    void listenToMousePressed(std::string, ecs::Entity*);
    void listenToMouseUp(std::string, ecs::Entity*);
    void listenToMouseScroll(ecs::Entity*);

private:
    // used to keep track of which scripts are currently in use
    class IdSet {
    public:
        IdSet() = default;
        ~IdSet() = default;

        void add(std::size_t);
        bool contains(std::size_t) const;
        void remove(std::size_t);

    private:
        std::unordered_map< std::size_t, int > ids_{};
    };

    Context&                context_;
    KeyboardManager&        keyboardManager_;
    MouseEvents&            mouseManager_;
    IdSet                   containedScripts_;
    std::set< std::size_t > updatedScripts_;
};

}   // system
}   // pg
