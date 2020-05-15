// Copyright(c) 2020 PaperSloth

using UnrealBuildTool;
using System.Collections.Generic;

public class RemapperExampleTarget : TargetRules
{
    public RemapperExampleTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        ExtraModuleNames.AddRange(new string[] { "RemapperExample" });
    }
}
