#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+9; 
int c,t,n,d;
int x[N],ft[N],bh[N],fft[N],bbh[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		x[n+1]=3e18+9;
		for(int i=1;i<=n;i++)ft[i]=0,bh[i]=0,fft[i]=0,bbh[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int r=1;
		for(int l=1;l<n-1;l++){
			int lr=r;
			while(x[r+1]-x[l]<=d){
				r++;
			}
			if(lr==r)continue;
			ft[r]=l;
			bh[l]=r;
		}
		for(int i=n;i>1;i--){
			if(bh[i]&&ft[i]&&bh[ft[i]]!=bh[i]){
				 int u=i;
				 while(bh[u]&&ft[u]){
				 	bh[ft[u]]=bh[i];
				 	u=ft[u];
				 }
			}
		}
		for(int i=1;i<n;i++){
			if(bh[i]&&ft[i]&&ft[bh[i]]!=ft[i]){
				 int u=i;
				 while(ft[u]&&bh[u]){
				 	ft[bh[u]]=ft[i];
				 	u=bh[u];
				 }
			}
		}
		for(int i=1;i<=n;i++)bbh[i]=max(max(bh[i],i),bbh[i-1]);
		for(int i=n-1;i>=1;i--)
		if(ft[i]==0)fft[i]=min(i,fft[i+1]);
		else fft[i]=min(ft[i],fft[i+1]);
		for(int i=1;i<n-1;i++){
			if(bh[i]&&ft[i+1]){
//				if(bh[i+1]==0)
				ans+=(bh[i]-i-1)*(i+1-ft[i+1]-1);
//				else if(fft[i+2]!=i&&bbh[i-1]!=i+1){
//					ans+=(fft[i+2]-ft[i+1])*(bh[i]-bbh[i-1]);
//				}
//				else{
//					ans+=(bh[i+1]-bh[i])*(i-ft[i+1]);
//				}
			}
		}
//		for(int i=1;i<=n;i++)cout<<ft[i]<<" ";
//		cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
/*
6 
 1200000000000000000
-1000000000000000000 
-600000000000000000 
-200000000000000000 
 200000000000000000 
 600000000000000000 
 1000000000000000000

*/
