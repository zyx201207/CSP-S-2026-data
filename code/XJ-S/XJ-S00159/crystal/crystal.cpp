#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m,a[N],d[N],sum[N],ans,di[N],sd[N],q[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
		//,cout<<d[i]<<' ';
		//cout<<'\n';
		for(int i=2;i<=n;i++)di[i]=di[i-1]+d[i-1]*(i-1);
		//,cout<<di[i]<<' ';
		//cout<<'\n';
		for(int i=1;i<=n;i++)sd[i]=d[i-1]+sd[i-1];
		//,cout<<sd[i]<<' ';
		//cout<<'\n';
		//for(int i=n;i>0;i--)suf[i]=suf[i+1]+d[i];
		for(int i=1;i<=n-1;i++){
			for(int j=i;j<=n;j++){
				int cnt=0;
				for(int k=1;k<=i-1;k++)cnt+=sd[j]-sd[k];
				if(di[j]-cnt<=m){
					ans=max(ans,j-i+1);
				}
				//cout<<i<<' '<<j<<' '<<di[i]<<" "<<cnt<<'\n';
			}
		}
		cout<<ans;	
	}
	else{
		int ci=a[2]-a[1],x=0,tot=0;
		for(int i=2;i<=n;i++)q[i]=i*(i-1)/2*ci;
		int anss=lower_bound(q+1,q+1+n,m)-q-1;
		cout<<anss;
	}
	return 0;
} 
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7

