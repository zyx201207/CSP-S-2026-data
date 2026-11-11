#include<bits/stdc++.h>
#define ll long long
#define P pair<int,int>
using namespace std;
const int maxN=1e6+10;
const ll INF=1e18+10;
ll _,c,n,m,d,q,s,t,f[maxN],b[maxN],mx[maxN],a[maxN],ans;
void dfs(ll x,ll res){
	if(mx[x]==res) f[x]++;
	else if(mx[x]>res) mx[x]=res,f[x]=1;
	for(int i=x+1;i<=n;i++)
		if(abs(a[i]-a[x])<=d) dfs(i,res+1);
}
void __(){
	cin>>n>>d,ans=0ll;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c<=10){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[j]=0ll,mx[j]=INF;
			dfs(i,0);
			for(int j=i+1;j<=n;j++) ans+=(f[j]==2);
		}
		cout<<ans<<'\n';
	}
	else if(c==11||c==12){
		if(a[1]==a[2]){
			cout<<ans<<'\n';
			return;
		}
		ll k=d/abs(a[1]-a[2]);
		if(k<=1){
			cout<<ans<<'\n';
			return;
		} 
		else{
			ans=(n-2*k+1)*(k-1);
			for(int i=n-2*k+2;i<n-k;i++) ans+=k-1-2*(n-k-i);
			cout<<ans<<'\n';
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>c>>_;
	while(_--)__();
	return 0;
} 
