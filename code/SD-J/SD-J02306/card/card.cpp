#include<bits\stdc++.h>

using namespace std;
const int N=5e5+5;
map<long long,int>mp;
int n,m,a[N],f,ans[N],ff,last[N],pre[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);//zn cin cout
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
		if(a[i]==a[i+1]&&i!=n)	ff=1;
		mp[a[i]]++;
		last[a[i]]=max(last[a[i]],i);
	}
	if(!f){
		for(int i=1;i<=n;i++){
			if(mp[a[i]]>1){
				ans[a[i]]=last[i];
			}
			else if(mp[i]==1&&mp[a[i-1]]==1){
				ans[a[i]]=i;
			}
			else{
				ans[a[i]]=n-i+1;
			} 
		}
		for(int i=1;i<=m;i++)	cout<<ans[i];
	}
	else{
		int fe[N]={0};
		for(int i=1;i<=n;i++)	fe[a[i]]=min(i,fe[a[i]]);
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(vis[a[j]]>1){
					vis[a[j]]--;
					vis[fe[a[j]]]--;
				}
				vis[a[j]]++;
			}
			for(int p=1;p<=m;p++)	if(vis[p]==1)	ans[p]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
} 
