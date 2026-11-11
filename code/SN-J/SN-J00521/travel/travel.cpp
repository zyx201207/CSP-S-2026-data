#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl '/n'
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	s1=" "+s1;
	s2=" "+s2;
	if(c1!=c2){
		ans="0000";
	}else{
		ans+="1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			ans+="1";
			if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
				if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
					ans+="1";
				}else{
					ans+="0";
				}
				if(abs(s1[3]-s2[3])==1){
					if(s1[3]=='C'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='C'){
						ans+="0";
					}else{
						ans+="1";
					}
				} 
			}
		}else{
			ans+="000";
		}
	}
	cout<<ans;
	return 0;
}
