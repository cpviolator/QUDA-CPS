#ifdef USE_SSE
#include <config.h>
CPS_START_NAMESPACE
/*! \file
  \brief  Routine used internally in the DiracOpWilson class.

  $Id: wilson_mdag.C,v 1.2 2011-02-26 00:19:27 chulwoo Exp $
*/
//--------------------------------------------------------------------
//  CVS keywords
//
//  $Author: chulwoo $
//  $Date: 2011-02-26 00:19:27 $
//  $Header: /home/chulwoo/CPS/repo/CVS/cps_only/cps_pp/src/util/dirac_op/d_op_wilson/sse/wilson_mdag.C,v 1.2 2011-02-26 00:19:27 chulwoo Exp $
//  $Id: wilson_mdag.C,v 1.2 2011-02-26 00:19:27 chulwoo Exp $
//  $Name: not supported by cvs2svn $
//  $Locker:  $
//  $Revision: 1.2 $
//  $Source: /home/chulwoo/CPS/repo/CVS/cps_only/cps_pp/src/util/dirac_op/d_op_wilson/sse/wilson_mdag.C,v $
//  $State: Exp $
//
//--------------------------------------------------------------------

CPS_END_NAMESPACE
#include <util/data_types.h>
#include <util/wilson.h>
#include <util/dirac_op.h>
CPS_START_NAMESPACE


//! Access to the elements of the \e SU(3) matrix
/*!
  Gets the element of the \e SU(3) matrix \e u with row \e row,
  column \e col and complex component \e d
*/
#define U(r,row,col,d,n,cb) *(u+(r+2*(row+3*(col+3*(d+4*(n+vol[0]*(cb)))))))
//! Access to the elements of a spinor vector.
/*!
  Gets the element of the spinor \e psi with spin \e s,
  colour \e c and complex component \e r
*/
#define PSI(r,c,s,n)     *(psi+(r+2*(c+3*(s+4*(n)))))
//! As above, but the vector is called chi
#define CHI(r,c,s,n)     *(chi+(r+2*(c+3*(s+4*(n)))))
#define TMP1(r,c,s,n)     *(tmp1+(r+2*(c+3*(s+4*(n)))))



void wilson_mdag(IFloat *chi_f, 
		 IFloat *u_f, 
		 IFloat *psi_f, 
		 IFloat kappa_f,
		 Wilson *wilson_p)
{
  IFloat *tmp1_f;
  int vol;
  int r, c, s, n;

/*--------------------------------------------------------------------------*/
/* Initializations                                                          */
/*--------------------------------------------------------------------------*/
  vol =  wilson_p->vol[0];
  tmp1_f = wilson_p->af[0];

  Float *chi = (Float *) chi_f;
  Float *psi = (Float *) psi_f;
  Float kappa = Float(kappa_f);

/*--------------------------------------------------------------------------*/
/* DslashDag_E0                                                             */
/*--------------------------------------------------------------------------*/
  wilson_dslash(tmp1_f, u_f, psi_f, 1, 1, wilson_p);

/*--------------------------------------------------------------------------*/
/* DslashDag_0E                                                             */
/*--------------------------------------------------------------------------*/
  wilson_dslash(chi_f, u_f, tmp1_f, 0, 1, wilson_p);

/*--------------------------------------------------------------------------*/
/* [1_OO - kappa * DslashDag_0E * DslashDag_E0] ]                           */
/*--------------------------------------------------------------------------*/
  for(n=0;n<vol;n++){
    for(s=0;s<4;s++){
      for(c=0;c<3;c++){
	for(r=0;r<2;r++){
	  CHI(r,c,s,n) = ( PSI(r,c,s,n) - kappa*kappa * CHI(r,c,s,n));
	}
      }
    }
  }
  DiracOp::CGflops += vol*24*2;

}







CPS_END_NAMESPACE
#endif
