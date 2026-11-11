#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2,ans;
bool check1(string sf,string ss){
	for(int i=0;i<=1;i++) if(sf[i]!=ss[i]) return false;
	return true;
}
bool check2(string sf,string ss){
	if((sf[2]>='A'&&sf[2]<='C')&&(ss[2]>='A'&&ss[2]<='C')) return true;
	if((sf[2]>='D'&&ss[2]<='F')||(sf[2]>='D'&&ss[2]=='F')) return true;
	return false;
}
bool check3(string sf,string ss){
	if((sf[2]=='A'&&ss[2]=='B')||(sf[2]=='B'&&ss[2]=='A')) return true;
	if((sf[2]=='B'&&ss[2]=='C')||(sf[2]=='C'&&ss[2]=='B')) return true;
	if((sf[2]=='D'&&ss[2]=='F')||(sf[2]=='F'&&ss[2]=='D')) return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans.push_back('1');
		if(check1(s1,s2)){
			ans.push_back('1');
			if(check2(s1,s2)){
				ans.push_back('1');
				if(check3(s1,s2)){
					ans.push_back('1');
					cout<<ans;
					return 0;
				}
				else{
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
