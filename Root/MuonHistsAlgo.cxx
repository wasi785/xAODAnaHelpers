#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>

#include <xAODMuon/MuonContainer.h>

#include <xAODAnaHelpers/MuonHistsAlgo.h>
#include <xAODAnaHelpers/MuonHists.h>
#include <xAODAnaHelpers/HelperFunctions.h>

// this is needed to distribute the algorithm to the workers
ClassImp(MuonHistsAlgo)

MuonHistsAlgo :: MuonHistsAlgo () :
IParticleHistsAlgo("MuonHistsAlgo")
{ }

StatusCode MuonHistsAlgo :: setupJob (EL::Job& job)
{
  job.useXAOD();
  xAOD::Init("MuonHistsAlgo").ignore();

  return StatusCode::SUCCESS;
}

StatusCode MuonHistsAlgo::AddHists( std::string name ) {
  return IParticleHistsAlgo::AddHists<MuonHists>(name);
}

StatusCode MuonHistsAlgo :: execute () {
  return IParticleHistsAlgo::execute<MuonHists, xAOD::MuonContainer>();
}
