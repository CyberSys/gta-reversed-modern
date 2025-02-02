#include "StdInc.h"

#include "AnimBlendClumpData.h"

void CAnimBlendClumpData::InjectHooks() {
    RH_ScopedClass(CAnimBlendClumpData);
    RH_ScopedCategory("Animation");

    RH_ScopedInstall(Constructor, 0x4CF0E0);
    RH_ScopedInstall(Destructor, 0x4CF100);
    RH_ScopedInstall(SetNumberOfBones, 0x4CF140);
    RH_ScopedInstall(ForAllFrames, 0x4CF190);
    RH_ScopedInstall(LoadFramesIntoSPR, 0x4CF1D0);
    RH_ScopedInstall(ForAllFramesInSPR, 0x4CF1E0);
}

// 0x4CF0E0
CAnimBlendClumpData::CAnimBlendClumpData() {
    m_NumFrames   = 0;
    m_PedPosition = nullptr;
    m_Frames      = nullptr;
}

// 0x4CF100
CAnimBlendClumpData::~CAnimBlendClumpData() {
    m_Anims.Remove();
    if (m_Frames) {
        CMemoryMgr::FreeAlign(&m_Frames);
    }
}

// 0x4CF140
void CAnimBlendClumpData::SetNumberOfBones(int32 numBones) {
    if (m_Frames) {
        CMemoryMgr::FreeAlign(&m_Frames);
    }
    m_NumFrames = numBones;
    m_Frames = reinterpret_cast<AnimBlendFrameData*>(CMemoryMgr::MallocAlign(sizeof(AnimBlendFrameData) * numBones, 64));
}

// 0x4CF190
void CAnimBlendClumpData::ForAllFrames(void (*callback)(AnimBlendFrameData*, void*), void* data) {
    for (auto& frame : std::span{ m_Frames, m_NumFrames }) {
        callback(&frame, data);
    }
}

// 0x4CF1D0
void CAnimBlendClumpData::LoadFramesIntoSPR() {
    // NOP
}

// 0x4CF1E0
void CAnimBlendClumpData::ForAllFramesInSPR(void (*callback)(AnimBlendFrameData*, void*), void* data, uint32 a3) {
    // NOP
}
