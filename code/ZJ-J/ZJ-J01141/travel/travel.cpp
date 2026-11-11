#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(r2[i]!=x2[i]){
			cout<<1000;
			return 0;
		}
	}
	if(r2[2]=='F')r=5;
	else r=r2[2]-'A'+1;
	if(x2[2]=='F')x=5;
	else x=x2[2]-'A'+1;
	if(r<=3&&x>=4||r>=4&&x<=3){
		cout<<1100;
		return 0;
	}
	if(abs(r-x)==1){
		cout<<1111;
		return 0;
	}
	else{
		cout<<1110;
		return 0;
	}
	return 0;
}