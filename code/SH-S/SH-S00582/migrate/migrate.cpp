#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,inf=1e18+10;
int c,T,n,d,x[N],sum;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int div=(x[n]-x[1])/(n-1),l;
		int nd=d/div;
		//cout<<div<<" "<<nd<<"\n";
		/*for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				l=abs(x[i]-x[j])/div;
				if(abs(l-2*nd)==1)sum++;
			}
		}*/
		l=2*nd-1ll;
		if(l>1)cout<<max(0ll,n-2*nd+1)<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
