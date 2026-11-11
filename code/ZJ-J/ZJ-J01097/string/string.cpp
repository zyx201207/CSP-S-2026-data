#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,w,i,s1,s2,ans,a[200010];
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	t=1;w=n;s1=a[1];s2=a[n];
	while(t<=w){
		if(b[t]!=b[w]) ans+=min(s1,s2);
		if(s1>s2) s1-=s2,s2=a[--w];
		else if(s1<s2) s2-=s1,s1=a[++t];
		else s1=a[++t],s2=a[--w];
	}
	cout<<ans;
} 
