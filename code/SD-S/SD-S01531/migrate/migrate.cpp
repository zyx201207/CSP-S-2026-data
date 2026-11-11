#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[20],ans,minn,res;
void m(int l,int r,int sp){
	if(sp>minn) return ;
	if(l>r) return ;
	if(l==r){
		if(minn>sp){
			minn=sp;
			res=1;
		}
		else if(minn==sp) res++;
		return ;
	}
	int nx=upper_bound(x+1,x+n+1,min(x[r],x[l]+d))-(x+1);
	nx--;
	m(nx,r,sp+1);
	if(nx>l) m(nx-1,r,sp+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				minn=1e17;
				res=0;
				m(i,j,0);
				if(res==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
