#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int tp=0;tp<t;tp++){
		long long n,d;
		cin>>n>>d;
		long long a[n+1];
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int cd=(n-i+d-1)/d+1;
			int qz[cd+1],bqz[cd+1];
			memset(qz,0,sizeof(qz));
			memset(bqz,0,sizeof(bqz));
			int s=1;
			for(int j=i+1;j<=n;j++){
				//cout<<s<<' '<<qz[s-1]<<' '<<qz[s]<<endl;
				if(a[j]<a[i]+s*d){
					qz[s]++;
					bqz[s]++;
				}else if(a[j]==a[i]+s*d){
					qz[s]++;
					s++;
				}else{
					s++;
				}
			}
			for(int j=1;j<=cd;j++)if(qz[j-1]==2)ans+=bqz[j];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
