// Copyright(c) 2020 PaperSloth

using UnrealBuildTool;

public class RemapperExample : ModuleRules
{
    public RemapperExample(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
