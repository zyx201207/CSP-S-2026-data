#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,c1,c2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
	}else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
	}else{
		cout<<"11";
		int x1=s1[2]-'A',x2=s2[2]-'A';
		if((x1<=2&&x2>2)||(x1>2&&x2<=2)){
			cout<<"00";
		}else{
			if((x1<=2&&x2<=2&&abs(x1-x2)==1)||(x1>2&&x2>2)){
				cout<<"11";
			}else{
				cout<<"10";
			}
		}
	}
	return 0;
}