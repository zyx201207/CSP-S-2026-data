#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ne[300005],cnt[500005],vis[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);  
	memset(ne,0,sizeof(ne));
	memset(vis,0,sizeof(vis));
	memset(cnt,0x7f,sizeof(cnt));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ne[a[i]]!=0&&vis[ne[a[i]]]!=2&&!vis[a[i]]){
			for(int j=ne[a[i]];j<i;j++){
				cnt[j]=min(j-ne[a[i]],cnt[j]);
				vis[j]=1;
			}
			vis[ne[a[i]]]=2;
		}
		ne[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])    ans[a[i]]+=i;
		else    ans[a[i]]+=cnt[i];
	}
	for(int i=1;i<=m;i++)    cout<<ans[i]<<" ";
	cout<<'\n';
	return 0;
}
