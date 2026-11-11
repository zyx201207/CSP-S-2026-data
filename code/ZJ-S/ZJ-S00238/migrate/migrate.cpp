#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000005],d;
int q[200005],h[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			q[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
			h[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(h[i]-q[j]==1){
//					cout<<i<<" "<<j<<endl;
					int qa=0,ha=0;
					if(q[i+1]>q[i]){
						for(int z=i;z>=0;z--){
							if(z-q[z]==1)qa++;
							else break;
						}
					}
					
					if(h[j-1]<h[j]){
						for(int z=j;z<=n;z++){
							if(h[z]-z==1)ha++;
							else break;
						}
					}
					ans+=(qa+1)*(ha+1);
				}
			}
		}
		cout<<ans<<'\n';
//		cout<<endl;
	}
	return 0;
}