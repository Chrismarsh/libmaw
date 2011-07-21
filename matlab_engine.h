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




#include <stdio.h>  // for FILENAME_MAX 
#ifdef WIN32
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
#endif

#include <engine.h>
#include <iostream>
#include <string>
#include <armadillo>
#include <exception>
#include <boost/lexical_cast.hpp>

namespace maw
{

class matlab_engine
{
public:

	/*
	Method: matlab_engine
		Creates a new Matlab engine instance. Should never create more than one
	Parameters: 
	Returns:   
		 - 
	Throws: 
	
	*/
	matlab_engine();


	/*
	Method: ~matlab_engine
		Shuts down the matlab engine instance if <stop> has not been called yet
	Parameters: 
	Returns:   
		 - 
	Throws: 
	
	*/
	~matlab_engine();

	
	/*
	Method: evaluate
		Takes the string command and evaluates it directly in the Matlab engine.
	Parameters: 
		std::string command - Command 
	Returns:   
		void
	Throws: 
		Runtime exception on error
	*/
	void evaluate(std::string command);

	/*
	Method: put
		Copies a mxArray type into the Matlab engine with a specified name
	Parameters: 
		std::string name - Name of the matrix in the Matlab engine
		mxArray * var - Array to put
	Returns:   
		void - 
	Throws: 
		runtime_error on failure
	
	*/
	void put(std::string name, mxArray* var );


	/*
	Method: put_double_matrix
		Puts an Armadillo type matrix into the engine
	Parameters: 
		std::string name - Name of the matrix in the Matlab engine
		const arma::mat * mat - Armadillo matrix instance to copy
	Returns:   
		void - 
	Throws: 
		runtime_error on failure
	*/
	void put_double_matrix(std::string name, const arma::mat* mat);

	/*
	Method: put_double_vector
		Put an Armadillo type vector into the engine
	Parameters: 
		std::string name - Name of the vector in the Matlab engine
		const arma::vec * vec - Armadillo vector instance to copy
	Returns:   
		void - 
	Throws: 
		runtime_error on failure
	*/
	void put_double_vector(std::string name, const arma::vec* vec);

	
	/*
	Method: get
		Copy a matrix from the engine to a mxArray instance
	Parameters: 
		std::string name - Name of the matrix in the engine to copy
	Returns:   
		mxArray* - A copy of the data. Client is responsible for memory free.
	Throws: 
		runtime_error on failure
	*/
	mxArray* get(std::string name);
	
	/*
	Method: get_double_matrix
		Copies a m x n matrix from the engine into an Armadillo matrix instance
	Parameters: 
		std::string name - Name of the matrix in the engine
	Returns:   
		arma::mat* - A copy of the data. Client is responsible for memory free.
	Throws: 
		runtime_error on failure
	*/
	arma::mat* get_double_matrix( std::string name);


	/*
	Method: get_double_vector
		Copies a n x 1 vector from the engine into an Armadillo vector instance
	Parameters: 
		std::string name - Name of the vector in the engine
	Returns:   
		arma::vec* - A copy of the data. Client is responsible for memory free
	Throws: 
		runtime_error on failure
	*/
	arma::vec* get_double_vector(std::string name);


	/*
	Method: get_scaler
		Get an 1 x 1 matrix from Matlab and convert it to a scaler.
	Parameters: 
		std::string name - Name of the scalar in the engine
	Returns:   
		double - A copy of the data
	Throws: 
		runtime_error on failure
	*/
	double get_scaler(std::string name);

	
	/*
	Method: set_working_dir
		Set the working directory of the engine to a specified directory
	Parameters: 
		std::string dir - Fully qualified or relative path to change directory to
	Returns:   
		void - 
	Throws: 
		runtime_error on failure
	*/
	void set_working_dir(std::string dir);

	
	/*
	Method: set_working_dir
		Set working directory for the engine to the current application's runtime directory
	Parameters: 
	Returns:   
		void - 
	Throws: 
		
	*/
	void set_working_dir(); 

	/*
	Method: get_last_error
		Get the last reported error from the engine as a string
	Parameters: 
	Returns:   
		std::string - The error as a string
	Throws: 
		
	*/
	std::string get_last_error();

	/*
	Method: start
		Initialize a new matlab engine
	Parameters: 
	Returns:   
		void - 
	Throws: 
		runtime_error on failures
	*/
	void start();


	/*
	Method: stop
		Closes a running matlab engine
	Parameters: 
	Returns:   
		void - 
	Throws: 
		runtime_error on failure
	*/
	void stop();

	
private:
	Engine *m_engine;

}; 

}