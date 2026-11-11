#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,sn,z,zn;
	int ans=0,m=0,n=0,l=0;
	cin>>s>>z>>sn>>zn;
	if(s==sn){
		cout<<"1";
		n=1;
	}
	else cout<<"0";
	for(int i=0;i<2;i++){
		if(z[i]==zn[i]){
			ans++;
		}
	}
	if(ans==2&&n==1){
		cout<<"1";
		l=1;
	}
	else cout<<"0";
	if((((z[2]=='A'||z[2]=='B'||z[2]=='C')&&(zn[2]=='A'||zn[2]=='B'||zn[2]=='C'))||((zn[2]=='F'||zn[2]=='D')&&(z[2]=='D'||z[2]=='F')))&&n==1&&l==1){
		cout<<"1";
		m=1;
	}else cout<<"0";
	if(abs(z[2]-zn[2])==1&&m==1&&l==1&&n==1)cout<<"1";
	else cout<<"0";
	return 0;
}
