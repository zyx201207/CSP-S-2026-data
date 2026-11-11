#include<iostream>
using namespace std;
int n,m,a[500010],nex[500010],vis[300010],ans[300010];
int fa(int now){
	if(nex[now])return nex[now]=fa(nex[now]);
	return now;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]])nex[vis[a[i]]]=i;
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			j=fa(j);
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}