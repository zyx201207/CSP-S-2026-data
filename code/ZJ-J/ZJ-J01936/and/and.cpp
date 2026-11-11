#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,a[200010],ans=INT_MAX;
map<ll,bool> mp={{0,1},{1,1},{3,1},{7,1},{15,1},{31,1},{63,1},{127,1},{255,1},{511,1},{1023,1},{2047,1},{4095,1},{8191,1},{16383,1},{32767,1},{65535,1},{131071,1},{262143,1},{524287,1},{1048575,1}};
bool cmp(ll a,ll b){return a>b;}
void dfs(ll id,ll cnt,ll res){
	if(id>n)return;
	if(cnt==m){
		ans=max(res,ans);
		return;
	}
	dfs(id+1,cnt+1,res&a[id]);
	dfs(id+1,cnt,res);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool b=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(!mp[a[i]])b=0;
	}
	if(b||n==m){
		sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=m;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	ans=0;
	dfs(1,0,INT_MAX);
	cout<<ans;
	return 0;
}
