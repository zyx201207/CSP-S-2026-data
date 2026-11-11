#include<bits/stdc++.h>
using namespace std;
long long a,s,d,n,m;
string a1,a2,a3,a4;
int o1,o2,o3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		cout<<1;
		o1=1;
	}else{
		cout<<0;
	}
	if(a2[0]==a4[0]&&a2[1]==a4[1]&&o1==1){
		cout<<1;
		o2=1;
	}else{
		cout<<0;
	}
	if((a2[2]<='C'&&a4[2]<='C'&&o2==1)||(a2[2]>='D'&&a4[2]>='D'&&o2==1)){
		cout<<1;
		o3=1;
	}else{
		cout<<0;
	}
	if(o3==1&&((a2[2]=='A'&&a4[2]=='B')
	||(a2[2]=='B'&&a4[2]=='A')
	||(a2[2]=='C'&&a4[2]=='B')
	||(a2[2]=='B'&&a4[2]=='C')
	||(a2[2]=='D'&&a4[2]=='E')
	||(a2[2]=='E'&&a4[2]=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
	/*
	Ãëµô¡£ 
	*/
}
