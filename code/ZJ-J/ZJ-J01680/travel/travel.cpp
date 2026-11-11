#include<bits/stdc++.h>
using namespace std;
int z[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	z[0]=1;
	z[1]=1;
	z[2]=1;
	z[3]=0;
	z[4]=0;
	z[5]=0;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}cout<<"1";
	int s=(b[0]-'0')*10+(b[1]-'0');
	int f=(d[0]-'0')*10+(d[1]-'0');
	if(f!=s){
		cout<<"000";
		return 0;
	}cout<<"1";
	int n=b[2]-'A';
	int m=d[2]-'A';
	if(z[n]!=z[m]){
		cout<<"00";
		return 0;
	}cout<<"1";
	if(z[n]==0){
		if(b[2]!=d[2]) cout<<"1";
		else cout<<"0";
	}else{
		if(b[2]==d[2]||(b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))cout<<"0";
		else cout<<"1";
	}
	return 0;
}