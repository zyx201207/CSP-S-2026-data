#include<bits/stdc++.h>
using namespace std;
const long long  MAX_N=5E5+78;
long long c,n,m,d,q,w1[MAX_N],t[405][405];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	if(c<=8){
		//弗洛伊德？ 
		for(long long i=1;i<=n;i++){
			cin>>w1[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j){
					t[i][j]=0;
				}else{
					t[i][j]=1E9;
				}
			}
		}
		vector<long long>v,w;
		for(long long u=1;u<=m;u++){
			long long k;
			cin>>k;
			for(long long j=1;j<=k;j++){
				long long V,W;
				cin>>V>>W;
				for(long long i=0;i<v.size();i++){
					t[v[i]][V]=min(t[v[i]][V],(W+w[i])*1);
					t[V][v[i]]=min(t[V][v[i]],(W+w[i])*1);
				}
				v.push_back(V);
				w.push_back(W);
			}
		}
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
					t[j][i]=min(t[j][i],t[j][k]+t[k][i]);
				}
			}
		}
//		cout<<"\n_______________________\n\n";
//		for(long long i=1;i<=n;i++){
//			for(long long j=1;j<=n;j++){
//				cout<<t[i][j]<<' ';
//			}cout<<'\n';
//		}
		while(q--){
			long long u,v;
			cin>>u>>v;
			cout<<t[u][v]+w1[u]+w1[v]<<'\n';
		}
	}else{
		//迪杰斯特拉? 
	} 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
