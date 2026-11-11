#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n,tot;
int f[N],g[N],to[N];
long long d;
long long x[N];
void solve(){
	tot=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int l,r=1;
	for(l=1;l<=n;l++){
		r=max(r,l);
		while(r<n&&x[r+1]-x[l]<=d)r++;
		to[l]=r;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		memset(g,0x3f,sizeof(g));
		memset(f,0,sizeof(f));
		g[i]=0;
		f[i]=1;
		for(int j=i;j<=n;j++){
			if(f[j]>2)continue;
			for(int k=j+1;k<=to[j];k++){
				if(g[j]+1==g[k])f[k]+=f[j];
				else if(g[j]+1<g[k])g[k]=g[j]+1,f[k]=f[j];
			}
		}
		for(int j=i+1;j<=n;j++)if(f[j]==2)ans++;
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
} 
