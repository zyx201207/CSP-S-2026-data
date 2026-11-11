//SN-S00483 胡海瑧 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int M=2e4+5;
int w[M];
int a[505][M],t[505][M],ans;
struct node{
	int w,v,z;
}h[M];
vector<node> vc[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			int a1,t1,a2,t2;cin>>a1>>t1>>a2>>t2;
			h[a1].w=t1,h[a1].v=a2,h[a1].z=t2;
			h[a2].w=t2,h[a2].v=a1,h[a2].z=t1;
//			vc[a1].push_back({t1,a2,t2});vc[a2].push_back({t2,a1,t1});
		}
		while(q--){
			int l,r;cin>>l>>r;
			ans+=(w[l]+w[r]);
			for(int i=l;i<=r;i++){
				ans+=h[i].w;ans+=h[i].z;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
