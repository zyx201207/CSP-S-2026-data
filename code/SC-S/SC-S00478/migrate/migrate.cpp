#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2e6+5;
int x[N],flx[N],frx[N];
int n,d,ans=0,id=0;
void work(){
	cin>>n>>d;
	ans=0;id=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=4;i<=n;i++)
		if(x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d&&x[i]-x[i-3]>d) frx[++id]=i,flx[id]=i-3;
	frx[id+1]=n+1;x[0]=-1e18;x[n+1]=1e18;
	for(int i=1;i<=id;i++)
	{
		int l=flx[i],r=frx[i];
		while(l>=flx[i-1]&&x[l]-x[l-1]<=d) l--;
		while(r<=frx[i+1]&&x[r+1]-x[r]<=d) r++;
		ans+=(flx[i]-l+1)*(r-frx[i]+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,c;cin>>c>>t;
	while(t--) work();
}