#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,a[500005],o,cnt,anss[500005];
bool v[500005];
struct subway{
	int a,b,time;
}vis[500005];
struct ti{
	int zz,titi;
}t[500005];
void find(ll qqq,ll zzz,ll ans){
	if(qqq==zzz){
		cnt++;
		anss[cnt]=ans+a[zzz];
	}
	for(ll i=1;i<=o;i++){
		if(vis[i].a==qqq&&v[i]==false){
			v[i]=true;
			find(vis[i].b,zzz,ans+vis[i].time);
			v[i]=false;
		}
		if(vis[i].b==qqq&&v[i]==false){
			v[i]=true;
			find(vis[i].a,zzz,ans+vis[i].time);
			v[i]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll i=1;i<=k;i++){
			cin>>t[i].zz>>t[i].titi;
		}
		for(ll i=1;i<=k;i++){
			for(ll j=i+1;j<=k;j++){
			o++;
			vis[o].a=t[i].zz;
			vis[o].b=t[j].zz;
			vis[o].time=t[i].titi+t[j].titi;
		}
		}
	}
	while(q--){
		cnt=0;
		memset(anss,0,sizeof(anss));
		ll qqq,zzz;
		cin>>qqq>>zzz;
		ll ans=a[qqq];
		find(qqq,zzz,ans);
		ll maxn=INT_MAX;
		for(int i=1;i<=cnt;i++)
		maxn=min(maxn,anss[i]);
		cout<<maxn<<endl;
	}
return 0;
}
