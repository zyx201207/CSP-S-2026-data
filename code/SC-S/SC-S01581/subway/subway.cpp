#include<bits/stdc++.h>
using namespace std;
const long long M=5e5+10,N=5e3+10,INF=1e8+10;
long long c,n,m,d,q;
long long w[M],ans[N][N],zhantai[M];
bool zhantaitf[M];
struct node{
	long long a,t;
};
vector<node> v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long A,T;
			cin>>A>>T;
			v[i].push_back({A,T});
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			zhantai[j]=INF;
			zhantaitf[j]=0;
		}
		zhantai[i]=0;
		zhantaitf[i]=1;
		long long WEI=i,wei=i,shu=INF;
		for(long long qwe=1;qwe<m;qwe++){
			for(node j:v[WEI]){
				if(!zhantaitf[j.a]&&zhantai[j.a]>zhantai[WEI]+j.t){
					zhantai[j.a]=zhantai[WEI]+j.t;
				}
			}
			for(long long j=1;j<=m;j++){
				if(!zhantaitf[j]&&zhantai[j]<shu){
					wei=j;
					shu=zhantai[j];
				}
			}
			zhantaitf[wei]=1;
			WEI=wei;
			wei=i;
			shu=INF;
		}
		for(long long j=1;j<=m;j++){
			ans[i][j]=zhantai[j];
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+ans[x][y]<<"\n";
	}
	return 0;
}