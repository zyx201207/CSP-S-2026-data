#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
const int N=2e6+10;
int x[N];
int cntt,cnt;
void dfs(int now,int step,int fin,int maxx){
	if(step>cnt)return;
	if(now>=fin){
		cntt++;
		return;
	}
	int maxs=x[now]+maxx;
	int nx=lower_bound(x+now,x+fin+1,min(x[fin],maxs))-x;
	if(x[nx]>maxs){
		for(int i=now;i<=nx-1;i++){
			dfs(i,step+1,fin,maxx);
		}
	}
	else{
		for(int i=now;i<=nx;i++){
			dfs(i,step+1,fin,maxx);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<' '<<j<<'\n';
//-4 -3 -2 -1 3 6
				cnt=0;
				int p=i;
				bool ok=true;
				while(x[p]<x[j]){
//					cout<<x[p]<<' '<<x[j]<<' ';
//					cout<<i<<' '<<j<<'\n';
					if(x[p]+d<x[p+1]){
						ok=false;
						break;
					}
					int nx=lower_bound(x+i,x+j+1,min(x[p]+d,x[j]))-x;
					if(x[p]+d<x[nx]){
						p=nx-1;
						cnt++;
					}
					else{
						p=nx;
						cnt++;
					}
				}
				if(!ok)continue;
				cntt=0;
//				cout<<i<<' '<<j<<'\n';
				dfs(i,0,j,d);
				if(cntt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
