#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int N=;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
//	cout<<ss1[0]<<ss1[1]<<ss1[2]<<"\n";
//	cout<<ss2[0]<<ss2[1]<<ss2[2]<<"\n";
//	cout<<('A'<=ss2[2] && ss2[2]<='C')<<"\n";
	if(cc1==cc2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(ss1[0]==ss2[0] && ss1[1]==ss2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(('A'<=ss1[2] && ss1[2]<='C') && ('A'<=ss2[2] && ss2[2]<='C')){
		cout<<1;
//		cout<<"ÔÚAC";
	}else if(('E'<=ss1[2] && ss1[2]<='F') && ('E'<=ss2[2] && ss2[2]<='F')){
		cout<<1;
//		cout<<"ÔÚBD"; 
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(int(ss1[2]-ss2[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}


