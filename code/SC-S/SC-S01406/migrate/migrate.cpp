#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[1001010];
struct st{
	int u;
	int val;
};
int diss[5010][5010];
int cnt;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(diss,0,sizeof diss);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int dis;
				if((a[j]-a[i])%d==0){
					dis=(a[j]-a[i])/d;
				}else{
					dis=(a[j]-a[i])/d+1;
				}
				diss[i][j]=dis;
			}
		}
		cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				int cz=diss[i][j]*d-(a[j]-a[i]);
				for(int k=i+1;k<j;k++){
					if(cz>=a[k]-a[k-1]){
						cnt++;
					}
				}
				if(cnt==2){
					for(int p=i;p<j;p++){
						if(a[p+1]-a[p]>d){
							ans--;
							break;
						}
					}
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}