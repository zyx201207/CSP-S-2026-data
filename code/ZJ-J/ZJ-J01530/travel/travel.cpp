#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<'1';
			if(65<=(int)a2[2]&&(int)a2[2]<=67&&65<=(int)b2[2]&&(int)b2[2]<=67||68<=(int)a2[2]&&(int)a2[2]<=69&&68<=(int)b2[2]&&(int)b2[2]<=69){
				cout<<'1';
				if(a2[2]==b2[2]+1||a2[2]==b2[2]-1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
