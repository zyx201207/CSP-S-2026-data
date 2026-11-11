#include<bits/stdc++.h>
using namespace std;
long long a[2000006],x[2000006];
long long f[2000006],b[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			f[k]=1;
			int sum=1,q=k;
			while(sum<n-k+1&&q<=n){
				for(int i=q;i<=n;i++){
					if(f[i]){
						for(int j=i+1;j<=n;j++){
							if(a[j]-a[i]>d){
								continue;
							}else{
								if(!x[j]||x[j]==i){
									f[j]+=f[i];
									x[j]=i;
									sum++;
								}
							}
						}
					}
				}
				q++;
			}
			for(int i=k;i<=n;i++){
				if(f[i]==2){
					ans++;
				}
				f[i]=0;
				x[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

