#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int rf[N],lf[N];
int qz[N],hz[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,j=1;i<=n;i++){
			while(j+1<=n && a[j+1]-a[i]<=d) j++;
			rf[i]=j;
		}
		for(int i=n,j=n;j>=1;j--){
			while(i-1>=1 && a[j]-a[i-1]<=d) i--;
			lf[j]=i;
		}
		for(int i=2;i<n;i++){
			if(lf[i]==i) continue;
			if(rf[lf[i]]==i) qz[i]=qz[lf[i]]+lf[i+1]-lf[i];
		}
		for(int i=n-1;i>1;i--){
			if(rf[i]==i) continue;
			if(lf[rf[i]]==i) hz[i]=hz[rf[i]]+rf[i]-rf[i-1];
		}
		for(int i=3;i<n;i++){
			if(lf[i]>=i-1 || rf[i-1]<=i) continue;
			if(rf[lf[i-1]]==i && lf[rf[i]]==i-1) ans+=(qz[lf[i-1]]+1ll)*(hz[rf[i]]+1);
			if(rf[lf[i-1]]==i) ans+=(qz[lf[i-1]]+1ll)*(max(0ll,min(rf[i]-1,rf[i-1])-rf[i-2]));
			if(lf[rf[i]]==i-1) ans+=(hz[rf[i]]+1ll)*(max(0ll,lf[i+1]-max(lf[i-1]+1,lf[i])));
			ans+=max(0ll,min(rf[i]-1,rf[i-1])-rf[i-2])*max(0ll,lf[i+1]-max(lf[i-1]+1,lf[i]));
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) rf[i]=lf[i]=qz[i]=hz[i]=0;
	}
	return 0;
}

/*

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
