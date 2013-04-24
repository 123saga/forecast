#include <vector>

#include <Rcpp.h>

extern "C" {

void etscalc(double *, int *, double *, int *, int *, int *, int *,
		double *, double *, double *, double *, double *, double *, double *);

void cpolyroot(double *opr, double *opi, int *degree,
			double *zeror, double *zeroi, Rboolean *fail);
}

class EtsTargetFunction {

public:

	//EtsTargetFunction();
	//~EtsTargetFunction();

	void eval(const double* p_var, int p_var_length);
	void init(std::vector<double> & p_y, int p_nstate, int p_errortype,
			int p_trendtype, int p_seasontype, bool p_damped,
			std::vector<double> & p_lower, std::vector<double> & p_upper, std::string p_opt_crit,
			double p_nmse, std::string p_bounds, int p_m, bool p_useAlpha, bool p_useBeta, bool p_useGamma,
			bool p_usePhi, double alpha, double beta, double gamma, double phi);

	static EtsTargetFunction* getTargetFunctionSingleton();
	static void deleteTargetFunctionSingleton();

	//double getLik() { return(lik); };
	double getObjVal() { return(objval); };

	/*
	std::vector<double>* gete() { return(&e); };

	double restrictions[4];
	 */

private:

	bool check_params();
	bool admissible();

	static EtsTargetFunction *EtsTargetFunctionSingleton;

	std::vector<double> par;
	std::vector<double> y;

	int nstate;
	int errortype;
	int trendtype;
	int seasontype;
	bool damped;
	std::vector<double> par_noopt;
	std::vector<double> lower;
	std::vector<double> upper;
	std::string opt_crit;
	double nmse;
	std::string bounds;
	int m;
	int n;

	std::vector<double> state;
	double alpha, beta, gamma, phi;

	std::vector<double> e;
	std::vector<double> amse;

	double lik, objval;

	bool useAlpha;
	bool useBeta;
	bool useGamma;
	bool usePhi;

};

