#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans;
string s="",s1="";
char c;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++)s=s+c,s1=c+s1;
		sum+=x;
	}
	for(int i=0;i<sum;i++){
		if(s[i]!=s1[i])ans++;
	}
	ans=ceil(ans/2.0);
	cout<<ans;
	return 0;
}

