#include<bits/stdc++.h>
using namespace std;
int w[500005];
//int sub[503][500005];
int a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,k,x,y;cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
	long long sum=0;
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		sum+=w[x];
		sum+=w[y];
		sum+=t[x];
		sum+=t[y];
	}
	
	return 0;
}
