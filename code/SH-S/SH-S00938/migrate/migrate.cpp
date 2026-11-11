#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t,n,ans,f[N];
long long a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int k=1;k<n;k++){
			for(int i=k+1;i<=n;i++) f[i]=1e9;
			f[k]=0;
			for(int i=k+1;i<=n;i++){
				int cnt=0;
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d){
						if(f[j]+1<f[i]){
							f[i]=f[j]+1;
							cnt=f[j]+1;
						}
						else if(f[j]+1==f[i]){
							cnt+=f[j]+1;
						}
					}
					else break;
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
