#include<bits/stdc++.h>
using namespace std;
int g[500009];
int cnt[300009];
int ans[300009];
int wz[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	for(int k=1;k<=n;k++){
		memset(cnt,0,sizeof cnt);
		for(int i=k;i<=n;i++){
			if(cnt[g[i]]==0) cnt[g[i]]=1,wz[g[i]]=i;
			else{
				for(int s=wz[g[i]]-1;s<=n;s++) if(wz[g[s]]>wz[g[i]]) cnt[s]=0,wz[s]=0;
				cnt[g[i]]=1;
				wz[g[i]]=i;
			}
		}
		for(int i=1;i<=m;i++) ans[i]+=cnt[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}