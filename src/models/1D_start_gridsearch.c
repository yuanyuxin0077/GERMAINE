/*------------------------------------------------------------------------
 *  Assemble 1D linear gradient model for grid search
 *
 *  D. Koehn
 *  Kiel, 19.12.2015
 *  ----------------------------------------------------------------------*/

#include "fd.h"

void model_gridsearch(float  ** Vp, float vp0, float grad0){

        /* global variables */
	extern int NX, NY;
	extern float DH;
        extern char  MFILE[STRING_SIZE];

	/* local variables */
	int i, j;
        int h = 23; /* depth of the seafloor (gridpoints) */
        float vp_water = 1500.0;
        char filename[STRING_SIZE];

        /*printf("vp0 = %e \t grad0 = %e \n",vp0,grad0);*/

	/* loop over global grid */
	for (i=1;i<=NX;i++){
		for (j=1;j<=NY;j++){

                     /* Vp[j][i] = vp_water;

                     if(j>=h){
		        Vp[j][i] = grad0 * ((j-h-1)*DH) + vp0;
                     }*/

                     Vp[j][i] = grad0 * ((j-1)*DH) + vp0;
                    
		}
	}

        /* output of model */
	/*sprintf(filename,"%s.rajzel_gs.vp",MFILE);
	writemod(filename,Vp,3);
	MPI_Barrier(MPI_COMM_WORLD);*/
	
}




