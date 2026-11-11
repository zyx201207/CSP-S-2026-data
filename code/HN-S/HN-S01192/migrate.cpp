#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;ll d;
ll x[N];
int p[N],q[N],c1[N],c2[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		/*
		0 1
		10 22
0 7 14 21 28 35 42 49 56 63
*/
		for(int i=1;i<=n;i++){
			cin>>x[i];	
		}
		int pr=0;
		for(int i=1;i<=n;i++){
			while(pr<n&&x[pr+1]<=x[i]+d)pr++;
			p[i]=pr;
			if(pr!=i)c1[pr]++;
		}
		pr=n+1;
		for(int i=n;i>=1;i--){
			while(pr>1&&x[pr-1]>=x[i]-d)pr--;
			q[i]=pr;
			if(pr!=i)c2[pr]++; 
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(q[i]!=i&&p[q[i]]==i){
				f[i]=f[q[i]];
				int k=q[q[i]+1];
				k--;
				f[i]+=k-q[q[i]]+1;
			}else f[i]=0;
//			cout<<f[i]<<" ";
		}
//		cout<<"\n";
		for(int i=n;i>=1;i--){
			if(p[i]!=i&&q[p[i]]==i){
				g[i]=g[p[i]];
				int k=p[p[i]-1];
				k++;
				g[i]+=p[p[i]]-k+1;
			}else g[i]=0;
		}
		for(int i=2;i<n;i++){
			if(p[i-1]==i||q[i]==i-1)continue;
			ans+=1ll*(g[i-1]+c2[i-1])*(f[i]+c1[i]);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)c1[i]=c2[i]=0;
	}
	return 0;
}

