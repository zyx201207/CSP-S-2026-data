#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a1,a2,b1,b2;
	cin>>a1>>b1>>a2>>b2;
	int flag1=1,flag2=1,flag3=0;
	for(int i=0;i<a1.size();i++) {
		if(a1[i]!=a2[i]) flag1=0;
	}
	for(int i=0;i<b1.size()-1;i++) {
		if(b1[i]!=b2[i]) flag2=0;
	}	
	ll l=b2.size()-1;
	int k=abs(b1[l]-b2[l]);
	if(flag1==1) cout<<"1";
	if(flag1==0) {
		cout<<"0000";
		return 0;
	}
	if(flag2==1) cout<<"1";
	if(flag2==0) {
		cout<<"000";
		return 0;
	}
	if((b1[l]>='A'&&b1[l]<='C'&&b2[l]>='A'&&b2[l]<='C')
	||((b2[l]=='D'||b2[l]=='F')&&(b1[l]=='D'||b1[l]=='F')))
		flag3=1;
	if(flag3) cout<<"1";
	if(!flag3) {
		cout<<"00";
		return 0;
	}
	if(k==1||(b1[l]=='D'&&b2[l]=='F')||(b2[l]=='D'&&b1[l]=='F')) 
		cout<<"1"; 
	else cout<<"0";
	return 0;
}
