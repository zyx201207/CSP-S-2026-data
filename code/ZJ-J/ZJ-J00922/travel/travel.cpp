#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,c1,s2,c2;
int ans1,ans2,ans3,ans4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s1>>c1>>s2>>c2;
	ans1=(s1==s2);
	if(ans1){
		if(c1[0]==c2[0]&&c1[1]==c2[1])ans2=1;
	}
	if(ans2){
		if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>='D'&&c2[2]>='D'))ans3=1;
	}
	if(ans3){
		if((c1[2]>='D'&&c2[2]>='D')||abs(c1[2]-c2[2])==1)ans4=1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
