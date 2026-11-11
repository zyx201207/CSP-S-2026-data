#include<bits/stdc++.h>
using namespace std;
#define int long long 
string c1,s1,c2,s2,ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		int a=(s1[0]-'0')*10+s1[1],b=(s2[0]-'0')*10+s2[1];
		if(a==b){
			ans+='1';
			char c=s1[2],d=s2[2];
			if(c>='A'&&c<='C'&&d>='A'&&d<='C'||c>='D'&&c<='E'&&d>='D'&&d<='E'){
				ans+='1';
				if(abs(c-d)==1){
					ans+='1';
				}else ans+='0';
			}else ans+="00";
			
		}else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}