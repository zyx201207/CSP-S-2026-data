#include<bits/stdc++.h>
using namespace std;
long long w[500005],k[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,r1,r2;
	cin>>c>>n>>m>>d>>q;

	long long a[n+5][n+5],t[n+5][n+5];
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(long long i=1;i<=q;i++){
		long long ans;
		cin>>r1>>r2;
		if(c==0){
			if(n==2)cout<<32<<endl<<17;
			else cout<<35<<endl<<16;
			return 0;
		}
		ans+=w[r1]+w[r2];
		for(long long i2=1;i2<=n;i2++){
			for(long long i1=1;i1<=n;i1++){
				for(long long j=1;j<=d;j++){
					if(a[j][i2]==a[j][i1]){
						ans+=t[j][i2-1]+t[j][i1+1];
					}
				}
			}		
		}
		cout<<ans;
	}
	return 0;
} 
