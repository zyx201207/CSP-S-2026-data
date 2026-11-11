#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,a[1000001],g[1001][1001],s1,s2,s3,s5,s4;
struct jo{
	int x,y;
};
vector<jo> g2[1000001];
void aaa(int q,int k){
//	cout<<q<<" "<<k<<" "<<s3<<"  666"<<"\n";
	if(k!=g[s4][q]||s3>2||k>g[s4][s5]) return ;
	if(q==s5){
		s3++;
		return ;
	}
	for(jo i:g2[q]){
		aaa(i.x,k+i.y);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=1e16;
			}
		}
		for(int i=1;i<=n;i++){
			g2[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) g[i][j]=0;
				else if(abs(a[i]-a[j])<=m){
					g2[i].push_back({j,1});
					g[i][j]=1;
					g[j][i]=1;
				} 
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<g[i][j]<<" ";
				s4=i;
				s5=j;
				
				aaa(i,0);
				if(s3==2) s2++;
//				cout<<i<<" "<<j<<" "<<(s3==2)<<"\n"; 
				s3=0;
			}
//			cout<<"\n";
		}
		cout<<s2<<"\n";
		s2=0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
