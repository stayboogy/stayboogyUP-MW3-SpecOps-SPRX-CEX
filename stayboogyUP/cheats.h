// Copyright (c) 2022, stayboogy@github.com, stayboogy@mail.com, M.C.
//
// stayboogy did it!
//

// cheats.h

//
// cheats.h begin
//

// Manly?
bool isMan;

// Godly?
bool isGod;

// Godly Button | DPad Right
bool GButton;

// Manly Button | DPad Left
bool MButton;

// DPad Right | Godly Button
bool DRight;

// DPad Left | Manly Button
bool DLeft;

// Advanced UAV
//
void UAV()
{
	// Advanced UAV
	char uav[] = { 0x01 };
	PS3::WriteBytes(0x18DB880, uav, sizeof(uav));
	// Super UAV
	PS3::WriteBytes(0x018db8c4, uav, sizeof(uav));
	// show ping (not sure)
	PS3::WriteBytes(0x18DA40C, uav, sizeof(uav));
	// radar (not sure)
	char radar[] = { 0x02 };
	PS3::WriteBytes(0x5F067, radar, sizeof(radar));
}

// All Perks at once
//
void Perks()
{
	char perks[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
	PS3::WriteBytes(0x01227788, perks, sizeof(perks));
}

// Real God Mode
// Vision Sharpened
// Enemies and Vehicles miss you always
// Dogs will not bring you down
// Can Never Die
//
void UnBeatable()
{
	// string > bytes for activating Real God Mode
	// unknown reason why
	char godly[] = "81";
	PS3::WriteString(0x012272ea, godly);
	sleep(1000);
}

// Player Can Be Damaged
// Vision Sharpened
// strictly for wanting to end survival or chaos match and have score logged
// otherwise match never ends
//
void Beatable()
{
	//char manly[] = "80";
	char manly[] = "80";
	PS3::WriteString(0x012272ea, manly);
	sleep(1000);
}

// Ammo Full for all currently held Weapons & Equipment
// Secondary Weapon Rapid Fire No Reload
// Primary Weapon Extended Clips
//
void Loaded()
{
	char loaded[] = { 0x00, 0x90 };

	PS3::WriteBytes(0x01227631, loaded, sizeof(loaded));
	PS3::WriteBytes(0x01227649, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276cd, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276d9, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276b5, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276c1, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276d9, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012276e5, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012326f9, loaded, sizeof(loaded));
	PS3::WriteBytes(0x01232711, loaded, sizeof(loaded));
	PS3::WriteBytes(0x01232771, loaded, sizeof(loaded));
	PS3::WriteBytes(0x01232795, loaded, sizeof(loaded));
	PS3::WriteBytes(0x0123277d, loaded, sizeof(loaded));
	PS3::WriteBytes(0x01232789, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012327a1, loaded, sizeof(loaded));
	PS3::WriteBytes(0x012327ad, loaded, sizeof(loaded));
}

// Godly
//
void Godly()
{
	// if press DPad Right | Godly Button
	if (GetKey()==(PAD_RIGHT))
	{
		// set our bools
		DRight = true;
		GButton = true;

		// if already Manly
		if (isGod == false);
		{
			// become Godly
			UnBeatable();

			// for more reliable player state change
			isGod = true;
			sleep(1000);
			DRight = false;
			GButton = false;
		}
	}
}

// Manly
//
void Manly()
{
	// if DPad Left | Manly Button
	if (GetKey()==(PAD_LEFT))
	{
		// set our bools
		DLeft = true;
		MButton = true;

		// if already Godly
		if (isMan == false);
		{
			// become Manly
			Beatable();

			// for more reliable player state change
			isMan = true;
			sleep(1000);
			DLeft = false;
			MButton = false;
		}
	}
}

//
// cheats.h end
//


//
//UNUSED CODE FOR REFERENCE
//NOT WORKING IN SPEC OPS
//

//void Gravity()
//{
//	char gravity[] = "-100";
//	PS3::WriteString(0x8377B148, gravity);
//};

//void Speed()
//{
//*reinterpret_cast<char*>(0x000019780) = 0x44, 0xF9, 0xC0;
//}

//void Hops()
//{
//*reinterpret_cast<char*>(0x00173BB0) = 0x02;
//}

//VARIOUS WAYS TO DO THE SAME THING

//write_process(0x012327ad, loaded, sizeof(loaded));

//write_process(0x01227788, perks, sizeof(perks));

//write_process(0x5F067, radar, sizeof(radar));

//write_process(0x5F067, radar, sizeof(radar));

//write_process(0x18DB880, uav, sizeof(uav));
