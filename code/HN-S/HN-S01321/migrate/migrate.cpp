#include<bits/stdc++.h>
using namespace std;
//Oct31==Dec25?
long long c,t,n,d,x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long st=upper_bound(x+1,x+n+1,x[i]+d)-x-1,en=lower_bound(x+1,x+n+1,x[j]-d)-x;
				if(st-en+1==2&&st<j&&en>i){
					long long l=1,r=1;
					for(int k=i;k>=1;k--){
						if(k>1&&x[k]-x[k-1]>d) break;
						if(k>2&&x[k]-x[k-2]<=d) break;
						if(k>1&&x[k+1]-x[k-1]<=d){
							break;
						}
						l++;
					}
					for(int k=j;k<=n;k++){
						if(k<n&&x[k+1]-x[k]>d) break;
						if(k<n-1&&x[k+2]-x[k]<=d) break;
						if(k<n&&x[k+1]-x[k-1]<=d) {
							break;
						}
						r++;
					}
					if(i==1) l=1;
					if(j==n) r=1;
					ans+=l*r;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
