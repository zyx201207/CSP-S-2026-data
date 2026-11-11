#include<bits/stdc++.h>
#define int long long
using namespace std;
#define maxn 500005
int t[3][maxn];
int t2[3][maxn];
int tm2[3][maxn]; 
int w[maxn];
int c, n,m,d,q;
#define endl '\n'
void worka(){
    int mk=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		mk=max(mk,k);
		for(int j=1;j<=k;j++){
			cin>>t[i][j];
			cin>>tm2[i][t[i][j]];
			t2[i][t[i][j]]=1;
		}
	}
	int ans=INT_MAX;
	for(int i=1;i<=m;i++){
		if(t2[1][i]==1&&t2[2][i]==1){
			ans=min(ans,tm2[1][i]+tm2[2][i]);
    	}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int sum=0;
		sum+=w[u]+w[v];
		if(n==1){
			cout<<sum+tm2[1][u]+tm2[1][v];
		}
		if(n==2){
			bool f=0;
			if(t2[1][u]==1&&t2[1][v]==1){
			    sum=w[u]+w[v]+tm2[1][u]+tm2[1][v];
			    f++;
			}
			if(t2[2][u]==1&&t2[2][v]==1){
				f++;
				sum=w[u]+w[v]+tm2[2][u]+tm2[2][v];
			}
			if(f==2){
				cout<<max(sum,w[u]+w[v]+tm2[1][u]+tm2[1][v]);
				continue;
			}
			if(f==1){
				cout<<sum;
				continue;
			}
			else if(f==0){
			
				ans=ans+w[u]+w[v];
				if(t2[1][u]==1){
					ans+=tm2[1][u];
				}
				else{
					ans+=tm2[2][u];
				}
				if(t2[1][v]==1){
					ans+=tm2[1][v];
				}
				else{
					ans+=tm2[2][v];
				}
				
				cout<<ans<<endl;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n<=2){
		worka();
	}
} 
