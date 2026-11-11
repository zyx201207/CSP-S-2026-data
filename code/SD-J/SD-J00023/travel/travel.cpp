#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(r2[0]+r2[1]==x2[0]+x2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'))||((r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(r2[2]-x2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
