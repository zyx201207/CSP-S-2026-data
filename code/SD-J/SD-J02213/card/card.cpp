#include<bits/stdc++.h>
using namespace std;
long long a[500010],vis[500010],nxt[500010],ans[500010],anss[500010],ise[500010],s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	nxt[n+1]=n+1; 
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0)	ise[i]=1,vis[a[i]]=1,nxt[i]=nxt[i+1];
		else	nxt[i]=i;
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++)	ans[i]=s[i];
	for(int i=1;i<=n;i++){
		if(ise[i]==1)	ans[a[i+1]]+=ans[a[i]];
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<' ';
	return 0;
}

