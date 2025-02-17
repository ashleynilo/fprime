// ======================================================================
// \title  SignalGen.hpp
// \author mstarch
// \brief  cpp file for SignalGen test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "SignalGenTester.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  SignalGenTester ::
    SignalGenTester() :
      SignalGenGTestBase("Tester", MAX_HISTORY_SIZE),
      component("SignalGen")
  {
    this->initComponents();
    this->connectPorts();
  }

  SignalGenTester ::
    ~SignalGenTester()
  {

  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void SignalGenTester ::
    test_start()
  {
       ASSERT_TLM_Output_SIZE(0);
       sendCmd_Toggle(0, 0);
       component.doDispatch();
       invoke_to_schedIn(0, 0);
       component.doDispatch();
       ASSERT_TLM_Output_SIZE(1);
  }
} // end namespace Ref
