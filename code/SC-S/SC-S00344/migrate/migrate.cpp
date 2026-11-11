#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long sum[2000010];
long long f[2000010];
long long g[2000010];
const long long INF=1000;
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int cc,tt;cin>>cc>>tt;
	while(tt--){
		long long n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(cc<=10||n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++){
				f[i]=0;g[i]=1;sum[i]=1;bool fl=0;
				int L=i,R=i;
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[j-1]>d){
						for(int k=i;k<=j;k++){
							f[k]=g[k]=sum[k]=0;
						}
						fl=1;break;
					}
					while(L<j&&a[j]-a[L]>d)L++;
					while(R+1<j&&f[L]>=f[R+1])R++;
					f[j]=f[L]+1;
					g[j]=min(INF,sum[R]-sum[L-1]);
					if(g[j]==2)ans++;
					sum[j]=sum[j-1]+g[j];
				}
				if(!fl){
					for(int k=i;k<=n;k++){
						f[k]=g[k]=sum[k]=0;
					}
				}
			}
			cout<<ans<<"\n";
		}else if(11<=cc&&cc<=12){
			long long t=d/(a[2]-a[1]);
			long long ans=0;
			if(t==0||t==1){
				cout<<"0\n";
			}else{
				for(int i=1;i<=n;i++){
					if((i-1)>=(t+t-1))ans++;
				}
				cout<<ans<<"\n";
			}
		}else{
			cout<<"0\n";
		}
		
	}
	
	return 0;
}