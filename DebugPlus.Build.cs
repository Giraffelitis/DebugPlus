// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DebugPlus : ModuleRules
{
	public DebugPlus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreOnline",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"VoiceChat",
			"SlateCore",
			"Json",

		});
	}
}
