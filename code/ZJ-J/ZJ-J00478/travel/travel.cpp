#include<bits/stdc++.h>
using namespace std;
const int N=114514;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	bool ans1=0,ans2=0,ans3=0,ans4=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				ans3=1;
				if((s1[2]<='C'&&abs(s1[2]-s2[2])==1)||(s1[2]>'C'&&abs(s1[2]-s2[2])==2)){
					ans4=1;
				}
			}
		}
	}
	printf("%d%d%d%d\n",(int)ans1,(int)ans2,(int)ans3,(int)ans4);
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
