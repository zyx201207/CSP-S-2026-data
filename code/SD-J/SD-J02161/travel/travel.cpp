#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
				cout<<"1";
				char l=min(s1[2],s2[2]),r=max(s1[2],s2[2]);
				if(l+1==r)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	return 0;
}//8:40
