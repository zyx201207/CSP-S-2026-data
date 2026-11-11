#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
int sum[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof a);
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+2;r<=n;r++){
				int b=d;
				int cnt=0;
				bool flag=0;
				for(int i=l+1;i<=r;i++){
					if(a[i]-a[i-1]>d){
						flag=1;
						break;
					}
					while(b>=a[i]-a[i-1]){
						b-=a[i]-a[i-1];
						i++;
					}
					i--;
					b=d;
					cnt++;
				}
				if(cnt!=r-l){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
