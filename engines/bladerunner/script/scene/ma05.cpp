/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/scene.h"

namespace BladeRunner {

void SceneScriptMA05::InitializeScene() {
	if (Global_Variable_Query(1) != 2 && Global_Variable_Query(1) != 3) {
		Setup_Scene_Information(-7204.0f, 953.97f, 1651.0f, 0);
	} else {
		Setup_Scene_Information(-7207.0f, 956.17f, 1564.0f, 0);
	}
	Scene_Exit_Add_2D_Exit(0, 432, 21, 471, 226, 1);
	Ambient_Sounds_Add_Looping_Sound(101, 90, 0, 1);
	Ambient_Sounds_Add_Looping_Sound(99, 40, -100, 1);
	Ambient_Sounds_Add_Looping_Sound(103, 50, 60, 1);
	Ambient_Sounds_Add_Speech_Sound(60, 0, 10, 260, 27, 47, -100, 100, -101, -101, 1, 1);
	Ambient_Sounds_Add_Speech_Sound(60, 20, 10, 260, 27, 47, -100, 100, -101, -101, 1, 1);
	Ambient_Sounds_Add_Speech_Sound(60, 40, 10, 260, 27, 47, -100, 100, -101, -101, 1, 1);
	Ambient_Sounds_Add_Speech_Sound(60, 50, 10, 260, 27, 47, -100, 100, -101, -101, 1, 1);
	Ambient_Sounds_Add_Sound(68, 10, 100, 25, 50, 0, 0, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(69, 10, 100, 25, 50, 0, 0, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(375, 10, 70, 50, 100, 0, 0, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(376, 10, 70, 50, 100, 0, 0, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(87, 10, 70, 25, 25, -100, 0, -101, -101, 0, 0);
	if (sub_401990()) {
		Ambient_Sounds_Add_Sound(403, 3, 3, 32, 32, 100, 100, -101, -101, 0, 0);
	}
	if (Global_Variable_Query(1) != 2 && Global_Variable_Query(1) != 3) {
		Scene_Loop_Start_Special(0, 0, 0);
	}
	Scene_Loop_Set_Default(1);
}

void SceneScriptMA05::SceneLoaded() {
	Obstacle_Object("Z-BOX-RAIL03", true);
	Footstep_Sounds_Set(0, 0);
	Footstep_Sounds_Set(1, 3);
}

bool SceneScriptMA05::MouseClick(int x, int y) {
	return false;
}

bool SceneScriptMA05::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool SceneScriptMA05::ClickedOnActor(int actorId) {
	return false;
}

bool SceneScriptMA05::ClickedOnItem(int itemId, bool a2) {
	return false;
}

bool SceneScriptMA05::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(0, -7199.0f, 956.17f, 1579.0f, 0, 0, false, 0)) {
			Loop_Actor_Walk_To_XYZ(0, -7199.0f, 956.17f, 1579.0f, 0, 0, false, 0);
			Game_Flag_Set(63);
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Async_Actor_Walk_To_XYZ(0, -7199.0f, 953.97f, 1685.0f, 0, false);
			Set_Enter(50, 50);
		}
		return true;
	}
	return false;
}

bool SceneScriptMA05::ClickedOn2DRegion(int region) {
	return false;
}

void SceneScriptMA05::SceneFrameAdvanced(int frame) {
	if (frame == 20) {
		Sound_Play(102, 70, -100, 100, 50);
	}
	//return true;	
}

void SceneScriptMA05::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void SceneScriptMA05::PlayerWalkedIn() {
	Music_Play(2, 52, 0, 2, -1, 0, 0);
	if ((Random_Query(0, 4) == 1 || (Game_Flag_Query(146) == 1 && !Game_Flag_Query(61))) && Global_Variable_Query(1) == 1) {
		Scene_Loop_Set_Default(1);
		Scene_Loop_Start_Special(2, 3, 1);
		Sound_Play(69, 100, 0, 0, 50);
	}
	if (Game_Flag_Query(146) && !Game_Flag_Query(61)) {
		if (!Game_Flag_Query(378)) {
			Actor_Voice_Over(1260, 99);
			Actor_Voice_Over(1270, 99);
			Actor_Voice_Over(1280, 99);
			Actor_Voice_Over(1290, 99);
		}
		Game_Flag_Set(61);
		Player_Gains_Control();
	}
	//return false;
}

void SceneScriptMA05::PlayerWalkedOut() {
}

void SceneScriptMA05::DialogueQueueFlushed(int a1) {
}

bool SceneScriptMA05::sub_401990() {
	return Global_Variable_Query(1) == 5
		&& !Actor_Clue_Query(0, 143)
		&& !Actor_Clue_Query(0, 144)
		&& !Actor_Clue_Query(0, 139)
		&& !Actor_Clue_Query(0, 140)
		&& !Actor_Clue_Query(0, 141)
		&& !Actor_Clue_Query(0, 142);
}

} // End of namespace BladeRunner
