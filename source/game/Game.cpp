#include "Game.h"

#include <iostream>

#include "engine/adl_entities/adlSun.h"
#include "engine/adl_entities/adlEntity_factory.h"

#include "game/Human.h"
#include "game/Interfaces/IMovementBehaviour.h"

Game::Game()
{

}

Game::~Game()
{

}

adlActor_shared_ptr human = MAKE_SHARED(Human);


bool Game::init()
{
	adlScene_shared_ptr scene = adl_scene_manager->create_empty_scene("new_scene");
	adl_scene_manager->set_active_scene(scene);

	scene->set_cube_map(adl_rm->get_cube_map("default"));

	Material_new_test new_test;
	Material_test test;
	Test_actor test_a;
	
	listener_ = ADL_NEW(Physics_listener);
	adl_scene_manager->add_physics_observer(listener_);

	adl_scene_manager->addToScene(human);
	human->setModel(adl_rm->getModel("head"));
	human->set_material(adl_rm->get_material("sapphire"));

	adlSun_shared_ptr sun = MAKE_SHARED(adlSun);
	sun->set_position(adlVec3(0, 300, 20));
	adl_scene_manager->setSun(sun);

	adlPoint_light_shared_ptr point_light = MAKE_SHARED(adlPoint_light);
	point_light->set_name("Light_#1");

	for (int i = 0; i < 1; i++)
	{
		adlActor_shared_ptr multi_actor = MAKE_SHARED(Material_test);
		adl_scene_manager->spawnActor(multi_actor, adlVec3(i * 5, 20, 0), adlVec3::zero(), adlVec3(1.0f));
	}

	adlCamera* camera = ADL_NEW(adlCamera);
	camera->set_camera_type(ct_god_mode);
	camera->init();

	//adl_scene_manager->add_plane();

	adl_scene_manager->set_camera(camera);

	adl_window->set_mouse_visible(false);

	scene->set_sun(sun);
	scene->set_camera(camera);

	adlTerrain_shared_ptr terrain = adl_rm->get_terrain("test_terrain");
	adl_scene_manager->set_terrain(terrain);

	return true;
}

bool Game::update(float dt)
{
	if (adl_input->get_key_up(adl_key_escape))
	{
		return false;
	}

	if (adl_input->get_key(adl_key_left_alt) && adl_input->get_key_down(adl_key_f))
	{
		adl_window->toggle_fullscreen();
	}

	Game x(Game());

	return true;
}
