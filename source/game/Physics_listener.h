#ifndef physics_listener_h__
#define physics_listener_h__

#include "../engine/adlPhysics_observer.h" 
#include "engine/adl_resource/adlResource_manager.h"
#include "engine/adlScene_manager.h"
#include "engine/adl_resource/adlTerrain.h"
#include "engine/adl_renderer/adlDebug_renderer.h"
#include "engine/adlInput.h"

class Physics_listener : public adlPhysics_observer
{
public:
	Physics_listener() {};
	~Physics_listener() {};

	virtual void on_collision_start(adlEntity_shared_ptr entity1, adlEntity_shared_ptr entity2) override
	{
	}

	virtual void on_collision_end(adlEntity_shared_ptr entity1, adlEntity_shared_ptr entity2)
	{
	}

	virtual void on_terrain_collision_start(adlEntity_shared_ptr entity, const adlVec3& collision_point)
	{
	}

	virtual void on_terrain_collision_end(adlEntity_shared_ptr entity)
	{
	}

	virtual void on_terrain_mouse_ray_collision(const adlVec3& collision_point) 
	{
	}

	virtual void on_mouse_collision_start(adlEntity_shared_ptr  entity)
	{
	}

private:
	bool selection_state_ = false;
	adlVec3 selection_start_;
	adlVec3 selection_current_;
};

#endif //physics_listener_h__