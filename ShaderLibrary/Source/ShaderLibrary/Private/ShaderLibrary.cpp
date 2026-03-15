#include "ShaderLibrary.h"
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"

void FShaderLibraryModule::StartupModule()
{
    // 현재 모듈 이름(ShaderLibrary)으로 플러그인을 찾습니다.
    // 만약 실제 플러그인 폴더명이 다르다면 그 폴더명을 직접 넣어야 합니다.
    TSharedPtr<IPlugin> MyPlugin = IPluginManager::Get().FindPlugin(TEXT("ShaderLibrary"));

    if (MyPlugin.IsValid())
    {
        // 플러그인 루트 밑의 "Shaders" 폴더 경로
        FString PluginShaderDir = FPaths::Combine(MyPlugin->GetBaseDir(), TEXT("Shaders"));

        // 매핑 이름을 "/Plugin/ShaderLibrary"로 변경 (더 명확하게)
        AddShaderSourceDirectoryMapping(TEXT("/Plugin/ShaderLibrary"), PluginShaderDir);
        
        UE_LOG(LogTemp, Log, TEXT("ShaderLibrary: Successfully mapped /Plugin/ShaderLibrary to %s"), *PluginShaderDir);
    }
    else
    {
        // 이 로그가 뜬다면 FindPlugin에 넣은 이름이 실제 .uplugin 파일명/폴더명과 다른 것입니다.
        UE_LOG(LogTemp, Error, TEXT("ShaderLibrary: Failed to find plugin 'ShaderLibrary'. Check your plugin name!"));
    }
}

void FShaderLibraryModule::ShutdownModule()
{
    // 종료 시 정리 로직 (필요 시)
}

IMPLEMENT_MODULE(FShaderLibraryModule, ShaderLibrary)