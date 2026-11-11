#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
long long mp[50005][50005],a[50005];
struct node{
	long long s,t;
}b[5005];
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	memset(mp,1e9,sizeof(mp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j].s>>b[j].t;
		}
		for(int j=1;j<=k;j++){
			for(int z=1;z<=k;z++){
				mp[b[j].s][b[z].s]=min(mp[b[j].s][b[z].s],b[j].t+b[z].t);
			}
		}
		
	} 
	while(q--){
		int s,e;
		cin>>s>>e;
		long long ans=mp[s][e]+a[s]+a[e];
		cout<<ans<<endl;
	}
	return 0;
}
