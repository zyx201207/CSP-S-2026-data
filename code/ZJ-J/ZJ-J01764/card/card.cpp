#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,v[200005],cnt[200005],ct,pm[200005];
map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ct=0;
		memset(cnt,0,sizeof(cnt));
		memset(pm,0,sizeof(pm));
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(!cnt[a[j]])cnt[a[j]]=j;
			pm[a[j]]++;
			if(pm[a[j]]>=2){
				for(int k=cnt[a[j]];k<j;k++){
					if(!v[k]){
						pm[a[k]]--;
						cnt[a[k]]=0;
						v[k]=1;
					}
				}
				cnt[a[j]]=j;
			}
		}for(int j=1;j<=m;j++)if(pm[j])mp[j]++;
	}for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
	return 0;
}