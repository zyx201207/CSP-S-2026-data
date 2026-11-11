#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3,f4;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		f1=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			f2=1;
			if(((64<s2[2]&&68>s2[2])&&(64<s4[2]&&68>s4[2]))||((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D'))){
				f3=1;
				if(abs(s2[2]-s4[2])==1)
					f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
