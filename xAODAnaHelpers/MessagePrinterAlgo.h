#ifndef xAODAnaHelpers_MessagePrinterAlgo_H
#define xAODAnaHelpers_MessagePrinterAlgo_H

// algorithm wrapper
#include "xAODAnaHelpers/Algorithm.h"

// external tools include(s):
#include <AsgTools/MessagePrinter.h>
#include <AsgTools/MessagePrinterOverlay.h>

// std include
#include <memory>

/**
  @rst
    This algorithm changes the format of the ``MsgStream`` objects for all other algorithms. There should only be on instance of it, and it should probably be first.

  @endrst
*/
class MessagePrinterAlgo : public xAH::Algorithm
{
  public:
    /// @brief Set the width of the name in the message
    unsigned int m_sourceWidth = 25;

  private:

    std::unique_ptr<asg::MessagePrinter>        m_messagePrinter{nullptr};
    std::unique_ptr<asg::MessagePrinterOverlay> m_messagePrinterOverlay{nullptr};

  public:
    // this is a standard constructor
    MessagePrinterAlgo (const std::string& name, ISvcLocator *pSvcLocator);

    // these are the functions inherited from Algorithm
    virtual StatusCode fileExecute ();
    virtual StatusCode histInitialize ();
    virtual StatusCode changeInput (bool firstFile);
    virtual StatusCode initialize ();
    virtual StatusCode execute ();
    virtual StatusCode finalize ();
    virtual StatusCode histFinalize ();

    /// @cond
    // this is needed to distribute the algorithm to the workers
    /// @endcond
};

#endif
