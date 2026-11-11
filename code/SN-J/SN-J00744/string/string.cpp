#include <bits/stdc++.h>
#include <iostream>
std::ifstream cin("string.in");
std::ofstream cout("string.out");
int main(){
	int n,ai,k=0,L=0;
	cin>>n;
	std::string ci;
	std::string S[50];
	for(int i=0;i<n;i++)
	{
		cin>>ai>>ci;
		L+=ai;
		for(int j=0;j<ai;j++)
		{
			S[L-ai+j]=ci;
			//cout<<S[L-ai+j];
		}
	}
	for(int i=0;i<L/2;i++){
		if(S[i]!=S[L-i-1]){
			k+=1;
			//cout<<S[i]<<S[L-i];
		}
	}
	cout<<k;
	return 0;
}
