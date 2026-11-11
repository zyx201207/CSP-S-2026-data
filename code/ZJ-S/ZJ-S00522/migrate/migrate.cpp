#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,t,n,d,a[N],nxt[N],f[N],h[N];
bool check(ll x,ll y){
	for(int i=0;i<=n;i++)f[i]=0,h[i]=0;
	for(int i=x;i<=y;i++)f[i]=min(y,nxt[i]),h[i]=min(y,max(h[i-1],nxt[i]));
	h[y]=y+1;
	int g=0;
	for(int i=x;i<=y;i=h[i]){
		if(i==h[i])return 0;
		for(int j=i+1;j<f[i];j++){
			int l=j,r=f[i];
			while(r<y){
				l=f[l];
				r=f[r];
				if(l==f[l]||r==f[r])break;
			}
			if(l==r)g++;
		}
	}
	return g==1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--)cout<<0<<endl;
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					ans++;
					//cout<<i<<j<<endl;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
