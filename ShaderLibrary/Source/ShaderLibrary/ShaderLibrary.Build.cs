// Copyright © 2026 BxKangKi. Licensed under the MIT License.

using UnrealBuildTool;

public class ShaderLibrary : ModuleRules
{
    public ShaderLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PublicDependencyModuleNames.AddRange(
        new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Projects",
            "RenderCore"
        }
    );
    }
}
