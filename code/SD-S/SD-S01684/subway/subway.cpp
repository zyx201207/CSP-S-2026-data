#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int c,n,m,d,q;
int o[N],k[3][N],t[3][N],w[N],k1[505][1005],t1[505][1005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
		int cnt=0;
		int r[N]={0},l[N]={0},op[N]={0},p[N];
		for(int i=1;i<=n;i++){
			cin>>o[i];
			for(int j=1;j<=o[i];j++){
				cin>>k[i][j]>>t[i][j];
				if(i==1){
					r[k[i][j]]=1;
				}
				if(i==2){
					l[k[i][j]]=1;
				}
			}
			
		}
		for(int i=1;i<=m;i++){
			if(r[i]&&l[i]){
				op[++cnt]=i;
				p[i]=t[1][i]+t[2][i];
			}
		}
		int ans=1e9;
		while(q--){
			int x,y;
			int flag=0;
			int o=0;
			int r1,l1;
			cin>>x>>y;
			if(r[x]&&r[y]){
				o=w[x]+w[y]+t[1][x]+t[1][y];
				ans=min(ans,o); 
				flag=1;
			}
			if(l[x]&&l[y]){
				o=w[x]+w[y]+t[2][x]+t[2][y];
				ans=min(ans,o); 
				flag=1;
			}
			if(!flag){
				if(r[x]){
					r1=1;
				}
				else{
					r1=2;
				}
				if(r[y]){
					l1=1;
				}
				else{
					l1=2;
				}
				for(int i=1;i<=cnt;i++){
					o=w[x]+w[y]+p[op[i]]+t[r1][x]+t[l1][y];
					ans=min(ans,o);
				}
			}
		cout<<ans<<endl;
			
		}
		return 0;
}
