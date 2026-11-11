#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,T,n,d,x[N],cnt,mind;

void dfs(int u,int ed,ll dist){
	if(dist>mind||cnt>2)return;
	if(u==ed){
		
		if(dist<mind){
			mind=dist;
			cnt=1;
		}else if(dist==mind)cnt++;
		return;
	}
	for(int i=ed;i>=u+1;i--){
		if(x[i]-x[u]>d)continue;
		dfs(i,ed,dist+1);
	}
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		cout<<0<<"\n";
		return;
	}
	int dd=x[2]-x[1],p=1;
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=dd){
			p=0;
			break;
		}
	}
	ll ans=0;
	if(p==1){
		d=d/dd;
		if(d<=1){
			cout<<0<<"\n";
		}else{
			cnt=min(d-1,n-d);
			for(int i=1;i<=n;i++){
				int l=0,r=cnt;
				while(l+1<r){
					int mid=(r-l)/2+l;
					if(mid<=n)l=mid;
					else r=mid;
				}
				ans+=l-(i+cnt);
//				for(int j=1;j<cnt;j++){
//					int k=i+cnt+j;
//					if(k<=n)ans++;
//				}
			}
			cout<<n-cnt<<"\n";
		}
		return;
	}
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0,mind=1e18;
			dfs(i,j,0);
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
