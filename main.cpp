/**********************************************
Name: Jamie Simpson
Class: CSCE 4600-001
Program: Process Simulator Pt.1 
File: Main function which declares instances
***********************************************/

#include "Processes.h"

int main(int argc,char* argv[]){
	std::string process_choice="all";
	std::string number_processors="both";
	if(argc==2)
		process_choice=argv[1];
	else if(argc>=3){
		process_choice=argv[1];
		number_processors=argv[2];
	}
	if(strcasecmp(process_choice.c_str(),"RR")!=0&&strcasecmp(process_choice.c_str(),"SJF")!=0&&strcasecmp(process_choice.c_str(),"FIFO")!=0&&strcasecmp(process_choice.c_str(),"all")!=0){
		std::cout<<"Error: Invalid processing method entered."<<std::endl;
		display_options();
		return 0;
	}
	if(strcasecmp(number_processors.c_str(),"both")!=0&&strcasecmp(number_processors.c_str(),"single")!=0&&strcasecmp(number_processors.c_str(),"quad")!=0){
		std::cout<<"Error: Invalid processor number entered."<<std::endl;
		display_options();
		return 0;
	}
	srand(time(NULL));//sends rand
	Process RR_single_processor;
	for(int i=0;i<TOTAL_PROCESSES;i++)
		RR_single_processor.add_process(i*TIME_QUANTUM);
	Process RR_quad_processor=RR_single_processor;
	Process FIFO_single_processor=RR_single_processor;
	Process FIFO_quad_processor=RR_single_processor;
	std::string process_method_used;	
	RR_single_processor.overall_stats();
	if(strcasecmp(process_choice.c_str(),"all")==0||strcasecmp(process_choice.c_str(),"rr")==0){
		process_method_used="Round Robin";
		if(strcasecmp(number_processors.c_str(),"single")==0||strcasecmp(number_processors.c_str(),"both")==0){
			RR_single_processor.round_robin(1,"round_robin_single.txt");
			std::cout<<"Finished "<<process_method_used<<"! Find process results in generated text file."<<std::endl;
			RR_single_processor.print_stats(1,process_method_used);
		}
		if(strcasecmp(number_processors.c_str(),"quad")==0||strcasecmp(number_processors.c_str(),"both")==0){
			RR_quad_processor.round_robin(4,"round_robin_quad.txt");
			std::cout<<"Finished "<<process_method_used<<"! Find process results in generated text file."<<std::endl;
			RR_quad_processor.print_stats(4,process_method_used);
		}
	}
	if(strcasecmp(process_choice.c_str(),"all")==0||strcasecmp(process_choice.c_str(),"fifo")==0){
		process_method_used="First In First Out";
		if(strcasecmp(number_processors.c_str(),"single")==0||strcasecmp(number_processors.c_str(),"both")==0){
			FIFO_single_processor.first_in_first_out(1,"first_in_first_out.txt");
			std::cout<<"Finished "<<process_method_used<<"! Find process results in generated text file."<<std::endl;
			FIFO_single_processor.print_stats(1,process_method_used);
		}
		if(strcasecmp(number_processors.c_str(),"quad")==0||strcasecmp(number_processors.c_str(),"both")==0){
			FIFO_quad_processor.first_in_first_out(4,"first_in_first_out.txt");
			std::cout<<"Finished "<<process_method_used<<"! Find process results in generated text file."<<std::endl;
			FIFO_quad_processor.print_stats(4,process_method_used);
		}
	}

//	if(strcasecmp(process_method.c_str(),"sjf")==0){
//		single_processor_processes.first_in_first_out(1,"first_in_first_out.txt");
//		quad_processor_processes.first_in_first_out(4,"first_in_first_out.txt");
//		process_method_used="Shortest Job First";
//	}
	return 0;
}

void display_options(){
	std::cout<<"First argument options are:"<<std::endl;
	std::cout<<"RR (Round Robin)"<<std::endl;
	std::cout<<"SJF (Shortest Job First)"<<std::endl;
	std::cout<<"FIFO (First In-First Out)"<<std::endl;
	std::cout<<"ALL (do all of the above individually (default))"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Second argument options are:"<<std::endl;
	std::cout<<"single (One processor)"<<std::endl;
	std::cout<<"quad (Four processors)"<<std::endl;
	std::cout<<"both (Do with both single and quad processors (default))"<<std::endl;
	std::cout<<std::endl;
}