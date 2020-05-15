// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PSInputRemapper : ModuleRules
{
    public PSInputRemapper(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
            }
            );

        PrivateIncludePaths.AddRange(
            new string[] {
            }
            );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "InputCore",
            }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
            }
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
            );
    }
}
