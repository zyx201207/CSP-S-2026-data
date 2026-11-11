#include <bits/stdc++.h>
using namespace std;
//¿ªlonglong
bool mlest;

double tlest,tleed;

void read(){

}

void init(){

}

void compute(){

}

void clear(){

}

void run(){
	read();
	init();
	compute();
	clear();
}

bool mleed;

void wa(){
	cerr<<"\n"<<tleed-tlest<<"ms\n"<<(&mleed-&mlest-1)/1024.0/1024.0<<"MB";
}

void fre(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	fre("hub");
	tlest=clock();
	run();
	tleed=clock();
	wa();
	return 0;
}

