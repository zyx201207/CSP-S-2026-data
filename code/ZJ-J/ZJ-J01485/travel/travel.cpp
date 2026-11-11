#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
int ans[10],bel[11010];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	bel['A']=bel['B']=bel['C']=1;
	bel['D']=bel['F']=0;
	if(s1==s3){
		ans[1]=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			ans[2]=1;
			if(bel[s2[2]]==bel[s4[2]]){
				ans[3]=1;
				if(abs(s2[2]-s4[2])==1&&s2[2]+s4[2]!='C'+'D'){
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}