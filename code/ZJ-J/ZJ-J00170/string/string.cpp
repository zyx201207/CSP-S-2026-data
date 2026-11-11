#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,t,w,ans,a[200010];
string s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>s[i];
	t=1;w=n;
	while(t<=w)
		if(s[t]==s[w]){
			if(a[t]==a[w]) t++,w--;
			else if(a[t]<a[w]) a[w]-=a[t],t++;
			else a[t]-=a[w],w--;
		}
		else{
			if(a[t]==a[w]) ans+=a[t],t++,w--;
			else if(a[t]<a[w]) ans+=a[t],a[w]-=a[t],t++;
			else ans+=a[w],a[t]-=a[w],w--;
		}
	cout<<ans;
	return 0;
}