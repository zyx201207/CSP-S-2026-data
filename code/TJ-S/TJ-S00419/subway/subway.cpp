#include<bits/stdc++.h>
using namespace std;
int a[10000000];
struct sta{
	int s,e,q;
};
sta g[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; 
	cin>>c>>n>>m>>d>>q;
	while(q--){
	 	for(int i=1;i<=n;i++)
	 	cin>>a[i];
	 	for(int i=1;i<=m;i++){
	 	int N,u,q;
	 	cin>>N;
	 	for(int i=1;i<=N;i++){
		 	cin>>u>>q;
		 	g[i].e=u,g[i].q=q;
		 	i==1?g[i].s=0:g[i].s=g[i-1].e;
		}
		g[1].s=g[N].e;
	 	}
	 	int s,e;
	 	cin>>s>>e;
	 	int ans=0;
	 	for(int i=s;i<=e;i++){
			ans+=g[i].q;		
	 }
	 ans+=a[s]+a[e];
	 cout<<ans;
}
	 return 0;
}
