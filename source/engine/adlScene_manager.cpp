#include "adlScene_manager.h"

#include "adl_renderer/adlRender_manager.h"


adlScene_manager::adlScene_manager()
{
}

void adlScene_manager::update(float dt)
{
	for (auto entity : entities_)
	{
		entity.update(dt);
	}

	for (auto actor : actors_)
	{
		actor->update(dt);
	}

	for (auto light : lights_)
	{
		light->update(dt);
	}
}

void adlScene_manager::render()
{
	adlRender_manager* renderer = &adlRender_manager::get();
	for (auto actor : actors_)
	{
		renderer->render(actor);
	}

	for (auto light : lights_)
	{
		renderer->render(light);
	}
}

void adlScene_manager::add_entity_to_active_scene(adlEntity entity)
{
	entity.init();
	entities_.push_back(entity);
}

void adlScene_manager::add_actor_to_active_scene(adlActor_shared_ptr actor)
{
	actor->init();
	actors_.push_back(actor);
}

void adlScene_manager::add_light_to_active_scene(adlLight_shared_ptr light)
{
	light->init();
	lights_.push_back(light);
	adlRender_manager* renderer = &adlRender_manager::get();
	renderer->set_light(light);
}

void adlScene_manager::spawn_actor(adlActor_shared_ptr actor, adlVec3 position, adlVec3 rotation/* = adlVec3(0.0f)*/, adlVec3 scale/* = adlVec3(1.0f)*/)
{
	actor->init();
	actors_.push_back(actor);
	actor->set_position(position);
	actor->set_rotation(rotation);
	actor->set_scale(scale);
}
