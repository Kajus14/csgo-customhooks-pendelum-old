#pragma once
#include <windows.h>
#include <iostream>
#include <cstdint>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <array>
#include <fstream>
#include <istream>
#include <unordered_map>
#include <intrin.h>
#include <filesystem>

#include "../utilities/singleton.hpp"
#include "../utilities/fnv.hpp"
#include "../utilities/utilities.hpp"
#include "../../dependencies/minhook/minhook.h"
#include "../interfaces/interfaces.hpp"
#include "../../source-sdk/sdk.hpp"
#include "../../core/hooks/hooks.hpp"
#include "../math/math.hpp"
#include "../../dependencies/utilities/renderer/renderer.hpp"
#include "../../dependencies/utilities/console/console.hpp"
#include "../utilities/csgo.hpp"

#include "renderer/tinyformat.h"

//interfaces
#define sig_client_state "A1 ? ? ? ? 8B 80 ? ? ? ? C3"
#define sig_directx "A1 ? ? ? ? 50 8B 08 FF 51 0C"
#define sig_input "B9 ? ? ? ? F3 0F 11 04 24 FF 50 10"
#define sig_glow_manager "0F 11 05 ? ? ? ? 83 C8 01 C7 05 ? ? ? ? 00 00 00 00"
#define sig_player_move_helper "8B 0D ? ? ? ? 8B 46 08 68"
#define sig_weapon_data "8B 35 ? ? ? ? FF 10 0F B7 C0"

//misc
#define sig_set_angles "55 8B EC 83 E4 F8 83 EC 64 53 56 57 8B F1"
#define sig_prediction_random_seed "8B 0D ? ? ? ? BA ? ? ? ? E8 ? ? ? ? 83 C4 04"

//hooks
#define sig_key_values_engine "85 C0 74 ? 51 6A ? 56 8B C8 E8 ? ? ? ? 8B F0"
#define sig_key_values_client "85 C0 74 ? 6A ? 6A ? 56 8B C8 E8 ? ? ? ? 8B F0"

namespace csgo {
	extern player_t* local_player;
	extern entity_t* entity;
	extern c_usercmd* cmd;
	extern vec3_t angles;
	inline vec3_t real_angles_vector;
	inline vec3_t real_angles = { 0, 0, 0 };
	inline vec3_t fake_angles = { 0, 0, 0 };
	inline vec3_t real_angles_stored = { 0, 0, 0 };

	extern bool send_packet;
	float server_time(c_usercmd* = nullptr);
}