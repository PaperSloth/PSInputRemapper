// Copyright(c) 2020 PaperSloth

using UnrealBuildTool;
using System.Collections.Generic;

public class RemapperExampleEditorTarget : TargetRules
{
    public RemapperExampleEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        ExtraModuleNames.AddRange(new string[] { "RemapperExample" });
    }
}
