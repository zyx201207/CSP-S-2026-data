#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,f,z,g[500][20000];
long long w[500005];
long long k,t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>f>>z;
            g[i][j]=f;
            t[i][f]=z;
        }
	}
	while(q--){
        cin>>x>>y;
        long long sum=w[x]+w[y];
        if(g[x][x]==x&&y==g[x][y]){
            sum+=t[x][x]+t[x][y];
            cout<<sum<<endl;
            continue;
        }
        else sum+=t[n][y]+t[n][n];
        for(int i=n-1;i>=1;i--){
            sum+=t[i][i]+t[i][i+1];
        }
        cout<<sum<<endl;
	}
	return 0;
}
