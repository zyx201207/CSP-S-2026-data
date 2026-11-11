#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,fla=0,a[500005],b[500005],ans[500005],rt[500005],c[500005];
pair<pair<int,int>,int> v[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	v[n+1].first.second=n;
	for(int i=n;i>=1;i--){
		if(b[a[i]]){
			v[i]={{0,0},b[a[i]]};
			fla=1;
		}else{
			if(fla)v[i]={{i,i},v[i+1].second};
			else v[i]={{i,v[i+1].first.second},v[i+1].second};
			fla=0;
		}
		b[a[i]]=i,c[i]++;
	}
	for(int i=1;i<=n;i++){
		rt[v[i].first.second+1]-=c[i],rt[v[i].first.first]+=c[i];
		c[v[i].second]+=c[i];
	}
	for(int i=1;i<=n;i++) rt[i]+=rt[i-1],ans[a[i]]+=rt[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
