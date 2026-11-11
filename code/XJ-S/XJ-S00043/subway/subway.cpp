#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,M=1e5+5;
int c,n,m,d,q,w[5*M],k,a[N][N],t[N][N],x[M],y[M],f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
	    cin>>k;
	    for(int j=1;j<=k;j++){
		    cin>>a[i][j]>>t[i][j];
	    }
    }
    for(int i=1;i<=q;i++){
    	cin>>x[i]>>y[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i-1;j>=1;j--){
		    f[j][i]=max(f[j][i],t[j][j]+t[j][i]);
		    cout<<f[j][i]<<" ";
	    }
	    cout<<endl;
	}
	for(int i=1;i<=q;i++){
		cout<<w[x[i]]+w[y[i]]+f[x[i]][y[i]]<<endl;
	}
	return 0;
} 
