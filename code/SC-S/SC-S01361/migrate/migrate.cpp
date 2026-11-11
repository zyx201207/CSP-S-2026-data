#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long a[200005],ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[0]=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int now=i,past=0;
				bool f=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[now]<=d&&a[k+1]-a[now]>d){
						if(past!=0&&a[k]-a[now-1]<=d&&a[k]-a[now-2]>d){
							if(f==0)f==1;
							if(f==1){
								f==0;
								break;
							}
						};
						past=now;
						now=k;
					}
				}
				if(a[j]-a[now]>d)break;
				if(f)ans++;
			} 
		} 
		cout<<ans<<endl;
	}
	return 0;
} 