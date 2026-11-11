#include<bits/stdc++.h>
#define ll long long
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1) cout<<"0000";
	else{
		if(r2[0]!=x2[0]||r2[1]!=x2[1]) cout<<"1000";
		else{
			if((r2[2]>='A'&&r2[2]<='C'&&x2[2]>='D'&&x2[2]<='F')||(r2[2]>='D'&&r2[2]<='F'&&x2[2]>='A'&&x2[2]<='C')) cout<<"1100";
			else{
				char r=r2[2],x=x2[2];
				int c=abs(r-x);
				if(c==1) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
