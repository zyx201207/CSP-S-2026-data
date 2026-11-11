#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
long long n,c,m,d,q,w[M],k[N],x[M],y[M],minn=1e18;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c;
	if(c>=20&&c<=21){
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1,A,T;i<=n;i++){
			cin>>k[i];
			long long sum=0;
			for(int j=1;j<=k[i];j++){
				cin>>A>>T;
				sum+=T;
			}
			minn=min(minn,sum);
		}
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=q;i++){
			cout<<minn+w[x[i]]+w[y[i]]<<'\n';
		}
	}
	return 0;
}
