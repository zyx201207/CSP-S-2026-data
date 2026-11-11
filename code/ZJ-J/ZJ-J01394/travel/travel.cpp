#include<bits/stdc++.h>
using namespace std;
string x1,x2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x1>>z1>>x2>>z2;
	if(x1==x2){
		cout<<1;
	}
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(z1[0]==z2[0] && z1[1]==z2[1]){
		cout<<1;
	}
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if((z1[2]-'D')>=0 && (z2[2]-'D')>=0){
		cout<<1;
	}
	else if((z1[2]-'D')<0 && (z2[2]-'D')<0){
		cout<<1;
	}
	else {
		cout<<0<<0;
		return 0;
	}
	if((z1[2]-z2[2])*(z1[2]-z2[2])==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
