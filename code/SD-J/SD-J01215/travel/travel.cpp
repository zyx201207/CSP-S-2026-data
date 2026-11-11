#include<bits/stdc++.h>
#define int long long 
using namespace std;
string sta1,sta2,stb1,stb2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>sta1>>sta2>>stb1>>stb2;
	if(sta1==stb1){
		cout<<1;
		if(sta2[0]==stb2[0]&&sta2[1]==stb2[1]){
			cout<<1;
			if((sta2[2]<='C'&&stb2[2]<='C')||(sta2[2]>='D'&&stb2[2]>='D')){
				cout<<1;
				if((abs(sta2[2]-stb2[2])==1)
				||((sta2[2]=='D')&&(stb2[2]=='F'))
				||((sta2[2]=='F')&&(stb2[2]=='D'))){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	cout<<'\n';
	return 0;
}
