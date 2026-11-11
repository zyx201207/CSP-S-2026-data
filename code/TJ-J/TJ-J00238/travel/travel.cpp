#include<bits/stdc++.h>

using namespace std;
#define int long long
int c1,c2;
string z1,z2; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
	}else{
		cout<<1;
		if(z1[0]!=z2[0] or z1[1]!=z2[1]){
			cout<<0<<0<<0;
		}else{
			cout<<1;
			if(((z1[2]=='A' or z1[2]=='B' or z1[2]=='C') and (z2[2]=='D' or z2[2]=='F')) or ((z2[2]=='A' or z2[2]=='B' or z2[2]=='C') and (z1[2]=='D' or z1[2]=='F'))){
				cout<<0<<0;
			}else{
				cout<<1;
				if(z1[2]+1==z2[2] or z2[2]+1==z1[2]){
					cout<<1;
				}
				else if((z1[2]=='D' and z2[2]=='F') or (z1[2]=='F' and z2[2]=='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
