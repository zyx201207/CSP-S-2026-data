#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				int v=a[k]-a[j],ans=0,t1;
				if(v%d!=0) t1=v/d+1;
				else t1=v/d;
				if(t1!=1&&k-j!=1&&a[k]-a[j]<d*t1){
					int cnt1=0,t2=0,t3=d;
					while(t3--){
						while(t2++){
							if(t2+t3==a[k]-a[j]){
								for(int s=1;s<=n;s++){
									if(a[s]==a[k]-t3) cnt1++;
								}
							}
						}
					}
					if(cnt1==2) ans++;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
} 
