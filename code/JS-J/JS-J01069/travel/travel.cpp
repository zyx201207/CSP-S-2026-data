#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]++;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[1]++;
			if(min(s1[2],s2[2])=='D' && max(s1[2],s2[2])=='F') ans[2]++,ans[3]++;
			else if(s1[2]!='D' && s2[2]!='D' && s1[2]!='F' && s1[2]!='F'){
				ans[2]++;
				if(abs(s1[2]-s2[2])==1) ans[3]++;
			}
		}
	}
	cout<<ans;
	return 0;
}
