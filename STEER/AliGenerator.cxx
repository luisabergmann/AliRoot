/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

/*
$Log$
*/

///////////////////////////////////////////////////////////////////
//                                                               //
//    Generate the final state of the interaction as the input   //
//    to the MonteCarlo                                          //
//
//Begin_Html
/*
<img src="picts/AliGeneratorClass.gif">
</pre>
<br clear=left>
<font size=+2 color=red>
<p>The responsible person for this module is
<a href="mailto:andreas.morsch@cern.ch">Andreas Morsch</a>.
</font>
<pre>
*/
//End_Html
//                                                               //
///////////////////////////////////////////////////////////////////

#include "AliGenerator.h"
#include "AliRun.h"

ClassImp(AliGenerator)

TGenerator* AliGenerator::fgMCEvGen=0;

//____________________________________________________________
AliGenerator::AliGenerator()
{
    printf("\n Initialising AliGenerator\n\n");
    
    gAlice->SetGenerator(this);
    SetThetaRange();
    SetPhiRange();
    SetMomentumRange();
    SetPtRange();
    SetYRange();
    SetNumberParticles();
    SetTrackingFlag();
  //
  //  fName="Default";
  //  fTitle="Base Generator Class";
  //
    fOrigin.Set(3);
    fOsigma.Set(3);
    fOrigin[0]=fOrigin[1]=fOrigin[2]=0;
    fOsigma[0]=fOsigma[1]=fOsigma[2]=0;
}

//____________________________________________________________
AliGenerator::AliGenerator(Int_t npart)
    : TNamed(" "," ")
{
    printf("\n Initialising AliGenerator\n\n");
    gAlice->SetGenerator(this);
    SetThetaRange();
    SetPhiRange();
    SetMomentumRange();
    SetPtRange();
    SetYRange();
    SetNumberParticles(npart);
    SetTrackingFlag();
  //
  //  fName="Default";
  //  fTitle="Base Generator Class";
  //
    fVertexSmear=none;
    fOrigin.Set(3);
    fOsigma.Set(3);
    fOrigin[0]=fOrigin[1]=fOrigin[2]=0;
    fOsigma[0]=fOsigma[1]=fOsigma[2]=0;
    fVMin.Set(3);
    fVMin[0]=fVMin[1]=fVMin[2]=0;
    fVMax.Set(3);
    fVMax[0]=fVMax[1]=fVMax[2]=10000;
}

//____________________________________________________________
AliGenerator::~AliGenerator()
{
  fOrigin.Set(0);
  fOsigma.Set(0);
  delete fgMCEvGen;
}

void AliGenerator::Init()
{   
}


