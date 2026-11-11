#include<bits/stdc++.h>
#define ll long long 
#define M 20005
#define N 505
#define Q 500005

using namespace std;
int c,n,m,d,q;ll w[M],k[M],a[N][N],t[N][N],ans=0;vector<ll>b[M];
void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];b[a[i][j]].push_back(k[i]);
			cin>>t[i][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		ans=0;ans+=w[x]+w[y];
		
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k[i];l++){
				if(a[j][l]==y){
					
				}
			}
		}
	}
	return 0;
} 
