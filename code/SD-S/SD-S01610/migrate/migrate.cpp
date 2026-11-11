#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,ans;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		vector<int>g;
		ans=0;
		cin>>n>>d>>x[1];
		if(n>=2){
			cin>>x[2];
		}
		if(n>=3){
			cin>>x[3];
		}
		g.push_back(0);
		for(int i=4;i<=n;i++){
			cin>>x[i];
			if(d<x[i]-x[i-3]&&x[i]-x[i-3]<2*d){
				g.push_back(i-3);
			}
		}
		if(g.size()==1){
			cout<<0<<"\n";
			continue;
		}
		g.push_back(n-2);
		for(int kx=1;kx<g.size()-1;kx++){
			int l=g[kx],r=g[kx]+4;
			while(l>0&&x[l]-x[max(l-1,(int)1)]<=d&&g[kx-1]<l){
				l--;
			}
			l++;
			while(r<n+1&&x[min(r+1,n)]-x[r]<=d&&g[kx+1]>r-3){
				r++;
			}
			r-=4;
			ans+=(g[kx]-l+1)*(r-g[kx]+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

