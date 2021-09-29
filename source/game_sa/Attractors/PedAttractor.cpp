#include "StdInc.h"

#include "PedAttractor.h"

void CPedAttractor::InjectHooks() {
    using namespace ReversibleHooks;
    // Install("CPedAttractor", "CPedAttractor", 0x5EDFB0, &CPedAttractor::Constructor);
    // Install("CPedAttractor", "~CPedAttractor", 0x5EC410, &CPedAttractor::Destructor);
    // Install("CPedAttractor", "SetTaskForPed", 0x5EECA0, &CPedAttractor::SetTaskForPed);
    // Install("CPedAttractor", "RegisterPed", 0x5EEE30, &CPedAttractor::RegisterPed);
    // Install("CPedAttractor", "DeRegisterPed", 0x5EC5B0, &CPedAttractor::DeRegisterPed);
    // Install("CPedAttractor", "IsRegisteredWithPed", 0x5EB4C0, &CPedAttractor::IsRegisteredWithPed);
    // Install("CPedAttractor", "IsAtHeadOfQueue", 0x5EB530, &CPedAttractor::IsAtHeadOfQueue);
    // Install("CPedAttractor", "GetTaskForPed", 0x5EC500, &CPedAttractor::GetTaskForPed);
    // Install("CPedAttractor", "GetTailOfQueue", 0x5EB5B0, &CPedAttractor::GetTailOfQueue);
    // Install("CPedAttractor", "GetQueueSlot", 0x5EB550, &CPedAttractor::GetQueueSlot);
    // Install("CPedAttractor", "GetNoOfRegisteredPeds", 0x5EAF10, &CPedAttractor::GetNoOfRegisteredPeds);
    // Install("CPedAttractor", "GetHeadOfQueue", 0x5EB590, &CPedAttractor::GetHeadOfQueue);
    // Install("CPedAttractor", "ComputeFreeSlot", 0x0, &CPedAttractor::ComputeFreeSlot);
    Install("CPedAttractor", "ComputeDeltaPos", 0x5E9600, &CPedAttractor::ComputeDeltaPos);
    Install("CPedAttractor", "ComputeDeltaHeading", 0x5E9640, &CPedAttractor::ComputeDeltaHeading);
    Install("CPedAttractor", "ComputeAttractTime", 0x5E95E0, &CPedAttractor::ComputeAttractTime);
    Install("CPedAttractor", "ComputeAttractPos", 0x5EA110, &CPedAttractor::ComputeAttractPos);
    Install("CPedAttractor", "ComputeAttractHeading", 0x5EA1C0, &CPedAttractor::ComputeAttractHeading);
    // Install("CPedAttractor", "BroadcastDeparture", 0x5EF160, &CPedAttractor::BroadcastDeparture);
    // Install("CPedAttractor", "BroadcastArrival", 0x5EEF80, &CPedAttractor::BroadcastArrival);
    // Install("CPedAttractor", "AbortPedTasks", 0x5EAF60, &CPedAttractor::AbortPedTasks);
}

// 0x5EAFD0
void* CPedAttractor::operator new(uint32 size) {
    return plugin::CallAndReturn<void*, 0x5EAFD0, uint32>(size);
}

// 0x5EAFE0
void CPedAttractor::operator delete(void* object) {
    plugin::Call<0x5EAFE0>(object);
}

// 0x5EDFB0
CPedAttractor::CPedAttractor(C2dEffect* effect, CEntity* entity, int32 a3, int32 a4, float a5, float time2, float time1, float a8, float a9, float range, float a11, float a12) {
    plugin::CallMethod<0x5EDFB0, CPedAttractor*, C2dEffect*, CEntity*, int32, int32, float, float, float, float, float, float, float, float>(this, effect, entity, a3, a4, a5, time2, time1, a8, a9, range, a11, a12);
}

// 0x5EC410
CPedAttractor::~CPedAttractor() {
    plugin::CallMethod<0x5EC410, CPedAttractor*>(this);
}

// 0x5EECA0
void CPedAttractor::SetTaskForPed(CPed* ped, CTask* task) {
    return plugin::CallMethod<0x5EECA0, CPedAttractor*, CPed*, CTask*>(this, ped, task);
}

// 0x5EEE30
bool CPedAttractor::RegisterPed(CPed* ped) {
    return plugin::CallMethodAndReturn<bool, 0x5EEE30, CPedAttractor*, CPed*>(this, ped);
}

// 0x5EC5B0
void CPedAttractor::DeRegisterPed(CPed* ped) {
    return plugin::CallMethod<0x5EC5B0, CPedAttractor*, CPed*>(this, ped);
}

// 0x5EB4C0
bool CPedAttractor::IsRegisteredWithPed(const CPed* ped) {
    return plugin::CallMethodAndReturn<bool, 0x5EB4C0, CPedAttractor*, const CPed*>(this, ped);
}

// 0x5EB530
bool CPedAttractor::IsAtHeadOfQueue(CPed* ped) {
    return plugin::CallMethodAndReturn<bool, 0x5EB530, CPedAttractor*, CPed*>(this, ped);
}

// 0x5EC500
CTask* CPedAttractor::GetTaskForPed(CPed* ped) {
    return plugin::CallMethodAndReturn<CTask*, 0x5EC500, CPedAttractor*>(this);
}

// 0x5EB5B0
uint32 CPedAttractor::GetTailOfQueue() {
    return plugin::CallMethodAndReturn<uint32, 0x5EB5B0, CPedAttractor*>(this);
}

// 0x5EB550
int32 CPedAttractor::GetQueueSlot(const CPed*) {
    return plugin::CallMethodAndReturn<int32, 0x5EB550, CPedAttractor*>(this);
}

// 0x5EAF10
bool CPedAttractor::GetNoOfRegisteredPeds() {
    return plugin::CallMethodAndReturn<bool, 0x5EAF10, CPedAttractor*>(this);
}

// 0x5EB590
void* CPedAttractor::GetHeadOfQueue() {
    return plugin::CallMethodAndReturn<void*, 0x5EB590, CPedAttractor*>(this);
}

int32 CPedAttractor::ComputeFreeSlot() {
    assert(0);
    return 0;
}

// 0x5E9600
float CPedAttractor::ComputeDeltaPos() const {
    return CGeneral::GetRandomNumberInRange(-m_fRange, m_fRange);
}

// 0x5E9640
float CPedAttractor::ComputeDeltaHeading() const {
    return CGeneral::GetRandomNumberInRange(-m_fDeltaHeading, m_fDeltaHeading);
}

// inlined
// 0x5E95E0
void CPedAttractor::ComputeAttractTime(int32 unused, bool time1_or_time2, float& outTime) const {
    if (time1_or_time2)
        outTime = time2;
    else
        outTime = time1;
}

// 0x5EA110
void CPedAttractor::ComputeAttractPos(int32 pedId, CVector& outPosn) {
    if (m_pEffect) {
        outPosn = m_vecAttractorPosn - queueMp * (float)pedId * m_vecQueueDir;

        if (pedId) {
            outPosn.x += ComputeDeltaPos();
            outPosn.y += ComputeDeltaPos();
        }
    }
}

// bQueue - bad name?
// 0x5EA1C0
void CPedAttractor::ComputeAttractHeading(int32 bQueue, float& heading) {
    if (m_pEffect) {
        if (bQueue)
            m_vecUseDir = m_vecQueueDir;

        heading = CGeneral::GetRadianAngleBetweenPoints(m_vecUseDir.x, m_vecUseDir.y, 0.0f, 0.0f);
        if (bQueue)
            heading += CPedAttractor::ComputeDeltaHeading();
    }
}

// 0x5EF160
void CPedAttractor::BroadcastDeparture(CPed* ped) {
    plugin::CallMethod<0x5EF160, CPedAttractor*, CPed*>(this, ped);
}

// 0x5EEF80
void CPedAttractor::BroadcastArrival(CPed* ped) {
    plugin::CallMethod<0x5EEF80, CPedAttractor*, CPed*>(this, ped);
}

// 0x5EAF60
void CPedAttractor::AbortPedTasks() {
    plugin::CallMethod<0x5EAF60, CPedAttractor*>(this);
}