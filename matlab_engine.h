// % Copyright (c) 2011, Chris Marsh
// 	% All rights reserved.
// 	% 
// 	% Redistribution and use in source and binary forms, with or without 
// 	% modification, are permitted provided that the following conditions are 
// 	% met:
// % 
// 	%     * Redistributions of source code must retain the above copyright 
// 	%       notice, this list of conditions and the following disclaimer.
// 	%     * Redistributions in binary form must reproduce the above copyright 
// 	%       notice, this list of conditions and the following disclaimer in 
// 	%       the documentation and/or other materials provided with the distribution
// 	%     * Neither the name of the University of Saskatchewan nor the names 
// 	%       of its contributors may be used to endorse or promote products derived 
// 	%       from this software without specific prior written permission.
// 	%       
// 	% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// 	% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// 	% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// 	% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// 	% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// 	% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// 	% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// 	% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// 	% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// 	% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// 	% POSSIBILITY OF SUCH DAMAGE.


#pragma once

#include <engine.h>
#include <iostream>
#include <direct.h> // for getcwd
#include <stdlib.h>// for MAX_PATH
#include <string>
#include <armadillo>

#include <boost/lexical_cast.hpp>



class matlab_engine
{
public:
	matlab_engine();
	~matlab_engine();

	
	
	void evaluate(std::string command);

	void put(std::string name, mxArray* var );
	void put_double_matrix(std::string name, const arma::mat* mat);//copies an existing array to matlab with the specified name
	void put_double_vector(std::string name, const arma::vec* vec);

	
	mxArray* get(std::string name);
	//only returns a m x n matrix
	arma::mat* get_double_matrix( std::string name);//for the moment let the client handle the memory 
	arma::vec* get_double_vector(std::string name);//for the moment let the client handle the memory 
	double get_scaler(std::string name);

	//set working directory for matlab engine to a specified directory
	void set_working_dir(std::string dir);

	//set working directory for matlab engine to the current applications working directory
	void set_working_dir(); 

	std::string get_last_error();

	void start();

	void stop();

	

private:
	Engine *m_engine;

}; 