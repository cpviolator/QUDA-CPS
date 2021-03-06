/*
 * Please do not edit this file.
 * It was generated using PAB's VML system.
 */

#include <alg/array_arg.h>
CPS_START_NAMESPACE
	 bool FloatArray::Encode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_ENCODE)) return false;
		 if ( !Vml(&vmls,instance) ) return false;
		 vmls.Destroy(); return true;
	 }

	 bool FloatArray::Decode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_DECODE)) return false;
		 if ( !Vml(&vmls,instance)) return false;
		 vmls.Destroy(); return true;
	 }
	 bool FloatArray::Vml(VML *vmls,char *instance){
		 if(!vml_FloatArray(vmls,instance,this)) return false;
	 return true;
	}


bool_t
vml_FloatArray (VML *vmls, char *name,FloatArray *objp)
{
	 vml_class_begin(vmls,"FloatArray",name);
	 if (!vml_array (vmls, "Floats", (char **)&objp->Floats.Floats_val, (u_int *) &objp->Floats.Floats_len, ~0,
		sizeof (Float), (vmlproc_t) vml_Float))
		 return FALSE;
	 vml_class_end(vmls,"FloatArray",name);
	return TRUE;
}
	 bool ParamArg::Encode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_ENCODE)) return false;
		 if ( !Vml(&vmls,instance) ) return false;
		 vmls.Destroy(); return true;
	 }

	 bool ParamArg::Decode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_DECODE)) return false;
		 if ( !Vml(&vmls,instance)) return false;
		 vmls.Destroy(); return true;
	 }
	 bool ParamArg::Vml(VML *vmls,char *instance){
		 if(!vml_ParamArg(vmls,instance,this)) return false;
	 return true;
	}


bool_t
vml_ParamArg (VML *vmls, char *name,ParamArg *objp)
{
	 vml_class_begin(vmls,"ParamArg",name);
	 if (!vml_string (vmls, "name", &objp->name, ~0))
		 return FALSE;
	 if (!vml_Float (vmls, "val", &objp->val))
		 return FALSE;
	 vml_class_end(vmls,"ParamArg",name);
	return TRUE;
}
	 bool ParamArray::Encode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_ENCODE)) return false;
		 if ( !Vml(&vmls,instance) ) return false;
		 vmls.Destroy(); return true;
	 }

	 bool ParamArray::Decode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_DECODE)) return false;
		 if ( !Vml(&vmls,instance)) return false;
		 vmls.Destroy(); return true;
	 }
	 bool ParamArray::Vml(VML *vmls,char *instance){
		 if(!vml_ParamArray(vmls,instance,this)) return false;
	 return true;
	}


bool_t
vml_ParamArray (VML *vmls, char *name,ParamArray *objp)
{
	 vml_class_begin(vmls,"ParamArray",name);
	 if (!vml_array (vmls, "params", (char **)&objp->params.params_val, (u_int *) &objp->params.params_len, ~0,
		sizeof (ParamArg), (vmlproc_t) vml_ParamArg))
		 return FALSE;
	 vml_class_end(vmls,"ParamArray",name);
	return TRUE;
}
	 bool IntArray::Encode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_ENCODE)) return false;
		 if ( !Vml(&vmls,instance) ) return false;
		 vmls.Destroy(); return true;
	 }

	 bool IntArray::Decode(char *filename,char *instance){
		 VML vmls;
		 if ( !vmls.Create(filename,VML_DECODE)) return false;
		 if ( !Vml(&vmls,instance)) return false;
		 vmls.Destroy(); return true;
	 }
	 bool IntArray::Vml(VML *vmls,char *instance){
		 if(!vml_IntArray(vmls,instance,this)) return false;
	 return true;
	}


bool_t
vml_IntArray (VML *vmls, char *name,IntArray *objp)
{
	 vml_class_begin(vmls,"IntArray",name);
	 if (!vml_array (vmls, "v", (char **)&objp->v.v_val, (u_int *) &objp->v.v_len, ~0,
		sizeof (int), (vmlproc_t) vml_int))
		 return FALSE;
	 vml_class_end(vmls,"IntArray",name);
	return TRUE;
}
CPS_END_NAMESPACE
