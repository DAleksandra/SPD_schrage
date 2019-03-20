#include <iostream>
#include <string>
#include <fstream>>
#include <algorithm>
#include <vector>

using namespace std;

struct RPQ {
	int R = -1;
	int P = -1;
	int Q = -1;
		
};
int main() 
{
	string Data_document;
	vector<RPQ> G, N;
	int Cmax=0, t = 0, k = 0;
	int tmp_r, e = 0, tmp_q;
	RPQ C; 
	int data_length, n;
	ifstream input;
	input.open("data.txt");
	if( input.good() == true )
{
    cout << "Uzyskano dostep do pliku!" << std::endl;
    //tu operacje na pliku
} else cout << "Dostep do pliku zostal zabroniony!" << std::endl;

	input >> data_length; 
	
	for(int i = 0; i < data_length; i++){
			input >> C.R >> C.P >> C.Q;
			N.push_back(C); 	
	}
	
	tmp_r = 1000000000000000;
	tmp_q = -1;
	
	//Schrage
	n = data_length;
		while(!G.empty() || !N.empty())
		{
			for(int  j = 0;j<N.size(); j++)
			{
				tmp_r=min(N[j].R,tmp_r);
				if(tmp_r == N[j].R) 
					e = j;					
			}
			while(!N.empty() && (tmp_r<=t))
			{
				G.push_back(N[e]);
				N.erase(N.begin() + e);
				tmp_r = 100000000000;
				for(int  j = 0;j<N.size(); j++)
			{
				tmp_r=min(N[j].R,tmp_r);
				if(tmp_r == N[j].R) 
					e = j;					
			}
			}
			if (G.empty())
			{
				t = tmp_r;
			}
			else
			{
				for(int  j = 0; j < G.size(); j++)
				{
					tmp_q = max(G[j].Q, tmp_q);
					if(tmp_q == G[j].Q) 
						e = j;					
				}
				t= t + G[e].P;
				Cmax=max(Cmax,t+G[e].Q);
				G.erase(G.begin() + e);
				k++;
				tmp_q = -1;
			}
			
		}
	
	std::cout<< Cmax;
	
	
}
