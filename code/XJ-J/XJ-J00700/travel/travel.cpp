#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	int n,ln,m,lm;
	char sn,sm;
	fin>>n>>ln>>sn>>m>>lm>>sm;
	if(n==m){
		fout<<1;
	}else{
		fout<<"0000";
		return 0;
	}
	if(ln==lm){
		fout<<1;
	}else{
		fout<<"000";
		return 0;
	}
	if((sn>='D'&&sm>='D')||(sn<'D'&&sm<'D')){
		fout<<1;
	}else{
		fout<<"00";
		return 0;
	}
	if((sn<'D'&&sm<'D'&&(sn+1==sm||sn-1==sm))||(sn=='D'&&sm=='F'||sn=='F'&&sm=='D')){
		fout<<1;
	}else{
		fout<<0;
	}
	return 0;
}