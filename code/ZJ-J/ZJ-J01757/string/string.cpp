#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream f_in("string.in");
	ofstream f_out("string.out");
	int L=0,n=0,a=0,num=0;
	char b,S[L];
	f_in>>n;
	for(int i=1;i<=n;i++){
		f_in>>a>>b;
		L+=a;
		for(int j=1;j<=a;j++){
			S[i*j]=b;
			f_out<<S[i*j];
		}
	}
	for(int i=1;i<=L/2;i++){
		if(S[i-1]==S[L-i]){
			num+=0;
		}else{
			num+=1;
		}
	}
	f_out<<num-1;
	return 0;
}
