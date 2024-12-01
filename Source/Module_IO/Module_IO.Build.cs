using UnrealBuildTool;

public class Module_IO : ModuleRules
{
	public Module_IO(ReadOnlyTargetRules Target) : base(Target)  // Make visible to Unreal build system
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
