#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll=long long;
int n;
ll m;
map<ll,int> mp;
ll pos[N],num[N],pnum[N],ppro[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;cin>>x;mp[x]++;
	}
	n=0;
	for(auto p:mp){
		ll x=p.first,y=p.second;
		n++,pos[n]=x,num[n]=y;
	}
	for(int i=1;i<=n;i++){
		pnum[i]=pnum[i-1]+num[i];ppro[i]=ppro[i-1]+pos[i]*num[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,id=i;
		ll cost=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((pnum[i]-pnum[mid-1])*pos[i]-(ppro[i]-ppro[mid-1])<=m)
				r=mid-1,id=mid,cost=(pnum[i]-pnum[mid-1])*pos[i]-(ppro[i]-ppro[mid-1]);
			else l=mid+1;
		}
		ll cnt=pnum[i]-pnum[id-1];
		if(id==1)ans=max(ans,cnt);
		else ans=max(ans,cnt+min(num[id-1],(m-cost)/(pos[i]-pos[id-1])));
	}
	cout<<ans<<endl;
	return 0;
} 
