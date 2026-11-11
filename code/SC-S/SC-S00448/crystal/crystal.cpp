#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0,f[500050]; 
ll a[500050],g[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	f[0]=g[0]=0;
	queue<ll> q;
	for(int i=1;i<=n;i++){
		ll flag=0;
		f[i]=f[i-1]+1;
		q.push(a[i]);
		while(g[i-1]-flag+f[i-1]*(a[i]-a[i-1])>m){
			flag+=a[i]-q.front();
			q.pop();
			f[i]--;
		}
		g[i]=g[i-1]-flag+f[i-1]*(a[i]-a[i-1]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
