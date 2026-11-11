#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2000005;

int c,T;
int n,d;
int x[N],ind[N],outd[N],qz[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		sort(x+1,x+n+1);
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		memset(qz,0,sizeof(qz));
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(x[j]-x[i]>d)break;
				ind[j]++,outd[i]++;
			}
		}
		int upc=0,dc=0;
		for(int i=1;i<=n;i++){
			if(upc==1&&dc==1)
				d=1;
			if(outd[i]>2||ind[i]>2||upc!=1||dc!=1)
				d=0;
			if(outd[i]==2)upc++;
			if(ind[i]==2)dc++;
		}
		cout<<upc<<'\n';
	}
	
	return 0;
}
