#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
struct node{
	long long v,sl;
}dp[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			long long ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				dp[i]={0,0};
				cin>>a[i];
			}
			for(int k=1;k<=n;k++){
				dp[k]={0,1};
				for(int i=k+1;i<=n;i++){
					long long bs=1e18,gs=0;
					for(int j=k;j<i;j++){
						if(a[i]-a[j]<=d){
							if(dp[j].v+1<bs){
								bs=dp[j].v+1;
								gs=dp[j].sl;
							}
							else if(dp[j].v+1==bs){
								gs+=dp[j].sl;
							}
						}
					}
					dp[i].sl=gs;
					dp[i].v=bs;
					if(gs==2){
						ans++;
					}
				}
			}	
			cout<<ans<<'\n';
		}
	}else{
		while(t--){
			long long gc;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			gc=a[2]-a[1];
			if(gc==0){
				cout<<0<<'\n';
			}
			d=d/gc;
			if(d<2||n<4){
				cout<<0<<'\n';
				continue;
			}
			n-=3;
			n-=(d-2)*2;
			cout<<max(n,0ll)<<'\n';
		}
	}
	return 0;
}
//lmy
