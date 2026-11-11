//SN-S00449 冯睦子 西安市渭北中学 
#include<bits/stdc++.h>
using namespace std;
long long m,n,d,q,c,kt[509],co[508][508];
//vector<long long> lu[508];
//struct T{
//	long long cos,lu;
//};
const long long INF=1e10;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			co[i][j]=INF;
		}
	}for(int i=1;i<=m;i++)
		cin>>kt[i];
	for(int i=1;i<=n;i++){
		long long k,a1,t1;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a[k+1],t[k+1];
			cin>>a[j]>>t[j];
			for(int zz=1;zz<=j;zz++){
				co[a[j]][a[zz]]=t[j]+t[zz];
				co[a[zz]][a[j]]=t[j]+t[zz];
//				c[a[j]][a[z]].lu=i;
//				c[a[z]][a[j]].lu=i;
//				lu[a[z]].push_back(a[j]);
//				lu[a[j]].push_back(a[z]);
			}
		}
	}for(int w=1;w<=m;w++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(co[i][w]!=INF&&co[w][j]!=INF)
					co[i][j]=min(co[i][j],co[i][w]+co[w][j]);
			}
		}
	}for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<co[x][y]+kt[x]+kt[y]<<'\n';
	}return 0;
}
