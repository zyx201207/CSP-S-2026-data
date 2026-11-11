#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ofstream fout("check.out");
	int cnt=0;
	while(1){
		system("data.exe");
		system("crystal.exe");
		system("baoli.exe");
		if(system("fc crystal.out baoli.out > nul")){
			fout<<"WA"<<++cnt;
			cout<<"WA"<<cnt;
			return 0;
		}
		fout<<"AC"<<++cnt<<"\n";
		cout<<"AC"<<cnt<<"\n";
	}
	return 0;
}
