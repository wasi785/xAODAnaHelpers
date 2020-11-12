#ifndef xAODAnaHelpers_ElectronHists_H
#define xAODAnaHelpers_ElectronHists_H

#include "xAODAnaHelpers/IParticleHists.h"
#include <xAODEgamma/ElectronContainer.h>
#include "xAODAnaHelpers/Electron.h"
#include "xAODAnaHelpers/EventInfo.h"
#include <AthContainers/DataVector.h>

ANA_MSG_HEADER(msgElectronHists)

class ElectronHists : public IParticleHists
{
  public:


    ElectronHists(std::string name, std::string detailStr);
    virtual ~ElectronHists() ;

    virtual StatusCode initialize();
    virtual StatusCode execute( const xAOD::Electron* electron, float eventWeight, const xAOD::EventInfo* eventInfo = 0);
    virtual StatusCode execute( const xAH::Electron*  electron, float eventWeight, const xAH::EventInfo*  eventInfo = 0);
    using HistogramManager::book; // make other overloaded version of book() to show up in subclass
    using IParticleHists::execute; // overload

  protected:

    virtual StatusCode execute( const xAOD::IParticle* particle, float eventWeight, const xAOD::EventInfo* eventInfo = 0 );
    virtual StatusCode execute( const xAH::Particle* particle,   float eventWeight, const xAH::EventInfo*  eventInfo = 0 );

    // holds bools that control which histograms are filled
    HelperClasses::ElectronInfoSwitch* m_infoSwitch;

  private:

    // Isolation
    std::map<std::string, TH1F *> m_isIsolated; 

    // PID
    std::map<std::string, TH1F *> m_PID; 

    // clean
    TH1F* m_ptcone20;                
    TH1F* m_ptcone30;                
    TH1F* m_ptcone40;                
    TH1F* m_ptvarcone20;             
    TH1F* m_ptvarcone30;             
    TH1F* m_ptvarcone40;             
    TH1F* m_topoetcone20;            
    TH1F* m_topoetcone30;            
    TH1F* m_topoetcone40;            

    // rel
    TH1F* m_ptcone20_rel;            
    TH1F* m_ptcone30_rel;            
    TH1F* m_ptcone40_rel;            
    TH1F* m_ptvarcone20_rel;         
    TH1F* m_ptvarcone30_rel;         
    TH1F* m_ptvarcone40_rel;         
    TH1F* m_topoetcone20_rel;        
    TH1F* m_topoetcone30_rel;        
    TH1F* m_topoetcone40_rel;        



};

#endif
