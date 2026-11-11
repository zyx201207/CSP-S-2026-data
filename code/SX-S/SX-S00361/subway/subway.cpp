#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool id[1000][10001];
ll n,m,ans=0,mas=0x3f3f3f,vis[1000][10001];
ll w[500005];
struct SW{
	ll id[100010];
	ll num;
	ll time[100010];
}a[1000];

int main(){
	ll c,d,q,k,x,y,xs,ys,mid=0x3f3f;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i].num;
		for(ll j=1;j<=a[i].num;j++){
			cin>>a[i].id[j]>>a[i].time[j];
			id[i][a[i].id[j]]=true;
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans=w[x]+w[y];
  		for(int i=1;i<=n;i++){
			if(id[i][x]=true){
				xs=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(id[i][y]=true){
				ys=i;
				break;
			}
		}
		ans+=a[xs].time[x]+a[ys].time[y];
		for(ll i=1;i<=m;i++){
			if(i==x||i==y){
				continue;
			}
			if(id[xs][i]==true&&id[ys][i]==true){
				mid=min(mid,a[xs].time[i]+a[ys].time[i]);
			}
		}
		ans+=mid;
		cout<<ans<<endl;
	}
	return 0;
}
