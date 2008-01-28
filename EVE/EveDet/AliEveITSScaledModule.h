// $Id$
// Main authors: Matevz Tadel & Alja Mrak-Tadel: 2006, 2007

/**************************************************************************
 * Copyright(c) 1998-2008, ALICE Experiment at CERN, all rights reserved. *
 * See http://aliceinfo.cern.ch/Offline/AliRoot/License.html for          *
 * full copyright notice.                                                 *
 **************************************************************************/

#ifndef ALIEVE_ITSScaledModule_H
#define ALIEVE_ITSScaledModule_H

#include <TEveUtil.h>
#include <EveDet/AliEveITSModule.h>

#include <TQObject.h>


/******************************************************************************/
// AliEveDigitScaleInfo
/******************************************************************************/

class AliEveDigitScaleInfo : public TQObject, public TEveRefBackPtr
{
public:
  enum StatType_e { kST_Occup, kST_Average, kST_Rms };

  // Bool_t           fAutoUpdatePalette;
private:
  AliEveDigitScaleInfo(const AliEveDigitScaleInfo&);            // Not implemented
  AliEveDigitScaleInfo& operator=(const AliEveDigitScaleInfo&); // Not implemented

protected:
  Int_t            fScale;        // Current scale.
  Int_t            fStatType;     // Digit scaling algorithm, see StatType_e.

  Bool_t           fSyncPalette;  // Synchronize palette on next usage.

public:
  AliEveDigitScaleInfo();
  virtual ~AliEveDigitScaleInfo() {}

  Int_t  GetScale() const { return fScale; }
  void   ScaleChanged(Int_t s);

  Int_t  GetStatType() const { return fStatType; }
  void   StatTypeChanged(Int_t t);

  Bool_t GetSyncPalette() const   { return fSyncPalette; }
  void   SetSyncPalette(Bool_t x) { fSyncPalette = x; }

  ClassDef(AliEveDigitScaleInfo, 1);
};

/******************************************************************************/
// ScaledDigit
/******************************************************************************/

/******************************************************************************/
// AliEveITSScaledModule
/******************************************************************************/

class AliEveITSScaledModule : public AliEveITSModule
{
  friend class ITSSDSubEditor;

public:
  struct ScaledDigit : public TObject
  {
  public:
    Int_t N;
    Float_t sum;
    Float_t sqr_sum;
    Int_t min_i,min_j;
    Int_t max_i,max_j;

    ScaledDigit();
    ScaledDigit(Int_t di, Int_t dj);

    void Dump() const;
  };

private:
  std::map<Int_t, ScaledDigit> fDigitsMap;

  AliEveITSScaledModule(const AliEveITSScaledModule&);            // Not implemented
  AliEveITSScaledModule& operator=(const AliEveITSScaledModule&); // Not implemented

protected:
  Int_t       fNx;   // per module
  Int_t       fNz;

  Int_t       fNCx;  // per cell
  Int_t       fNCz;

  AliEveDigitScaleInfo* fScaleInfo;

public:
  AliEveITSScaledModule(Int_t gid, AliEveITSDigitsInfo* info, AliEveDigitScaleInfo* si );
  virtual ~AliEveITSScaledModule();

  virtual void DigitSelected(Int_t idx);

  virtual void LoadQuads();
  void         SetQuadValues();

  void         SyncPalette();

  void         GetScaleData(Int_t& cnx, Int_t& cnz, Int_t& total);
  AliEveDigitScaleInfo*  GetScaleInfo() { return fScaleInfo; }

  ClassDef(AliEveITSScaledModule, 1); // Visualization of an ITS module with digits aggregated on a grid of pre-defined size.
}; // endclass AliEveITSScaledModule

#endif
