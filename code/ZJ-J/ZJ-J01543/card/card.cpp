#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],f[1000010],ans[1000010],anss[1000010],x;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) f[j]=ans[j]=0;
		for(int j=i;j<=n;j++){
			if(!f[a[j]]) f[a[j]]=j,ans[a[j]]=1;//cout<<ans[a[j]]<<"\n";
			else {
				for(int k=f[a[j]]+1;k<=j-1;k++) ans[a[k]]=0,f[a[k]]=0;
				f[a[j]]=j;
			}
//			cout<<f[a[j]]<<" "<<a[j]<<"\n";
		}
//		for(int j=1;j<=m;j++) cout<<ans[j]<<" ";cout<<"\n";
		for(int j=1;j<=m;j++)
			if(ans[j]) anss[j]++;
	}
	for(int i=1;i<=m;i++) cout<<anss[i]<<" ";
	return 0;
}