#include<bits/stdc++.h>
#define ll long long
using namespace std;
int  ans[10];
bool check(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)ans[0]=1;
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
	if(ans[1]==1&&check(s1[2])==check(s2[2]))ans[2]=1;
	if(ans[2]==1){
		if(s2[2]=='A'&&s1[2]=='C'||s2[2]=='C'&&s1[2]=='A');
		else ans[3]=1;
	}
	for(int i=0;i<4;++i)cout<<ans[i];
	return 0;
}
