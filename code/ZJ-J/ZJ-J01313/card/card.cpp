#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],st[500010],cnt[500010],tp;
bool flag1,vis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]<a[i-1]) flag1=1;
	}
	if(!flag1){
		for(int i=n;i>=1;i--)
			if(!vis[a[i]]) cnt[a[i]]=i,vis[a[i]]=1;
		for(int i=1;i<=m;i++){
			cout<<cnt[i];
			if(i!=m) cout<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) vis[a[j]]=1,st[++tp]=a[j];
			else while(st[tp]!=a[j]) vis[st[tp--]]=0;
		}
		while(tp) cnt[st[tp--]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}