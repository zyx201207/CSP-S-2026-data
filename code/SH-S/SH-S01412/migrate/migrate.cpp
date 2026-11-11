#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,xx[2000009],sum[2000009],dis[2000009];
struct Node{
	ll step,Loc;
};
ll pairNum(ll x){
	for(ll i=1;i<=n;i++) sum[i]=dis[i]=-1LL;
	sum[x]=1LL;
	dis[x]=0LL;
	for(ll i=x+1;i<=n;i++){
		for(ll j=i-1;j>=x;j--){
			if(xx[i]<=xx[j]+d&&(dis[j]+1LL<=dis[i]||dis[i]==-1)){
				if(dis[i]==-1LL||dis[j]+1LL<dis[i]){
					dis[i]=dis[j]+1;
					sum[i]=sum[j];
				}else{
					sum[i]+=sum[j];
				}
			}
			if(xx[i]>xx[j]+d) break;
		}
	}
	ll ans=0;
	for(ll i=x;i<=n;i++) if(sum[i]==2) ans++;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(ll i=1LL;i<=n;i++) cin>>xx[i];
			ll anss=0;
			if(n==1LL) cout<<0<<endl;
			else if(d>=(xx[2]-xx[1])+(xx[2]-xx[1])&&d<(xx[2]-xx[1])+(xx[2]-xx[1])+(xx[2]-xx[1])){
				cout<<max(0LL,n-3LL)<<endl;
			}
			else cout<<0<<endl;
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			ll anss=0;
			cin>>n>>d;
			for(ll i=1;i<=n;i++) cin>>xx[i];
			ll sunLoc1=-1,sunLoc2=-1;
			for(ll i=1;i<=n;i++){
				if(xx[i]-xx[1]<=d&&xx[n]-xx[i]<=d){
					if(sunLoc1==-1) sunLoc1=i;
					else if(sunLoc2==-1) sunLoc2=i;
					else{
						sunLoc1=-114;
						break;
					}
				}
			}
			if(sunLoc1==-114) cout<<0<<endl;
			else if(sunLoc2==-1){
				if(sunLoc1>=n-1) cout<<0<<endl;
				else{
					for(ll i=1;i<sunLoc1;i++){
						if(xx[sunLoc1+1]<=xx[i]+d&&xx[sunLoc1+2]>xx[i]+d) anss+=n-(sunLoc1+2)+1;
					}
					cout<<anss<<endl;
				}
			}else{
				if(sunLoc2==n) cout<<0<<endl;
				else{
					for(ll i=1;i<=sunLoc1-1;i++){
						if(xx[sunLoc2+1]<=xx[i]+d) cout<<0<<endl;
						else{
							anss+=n-(sunLoc2+1)+1;
						}	
					}
					cout<<anss<<endl;
				}
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>xx[i];
		ll anss=0;
		for(ll i=1LL;i<=n;i++){
			ll nww=pairNum(i);
			anss+=nww;
		}
		cout<<anss<<endl;
	}
	return 0;
}
