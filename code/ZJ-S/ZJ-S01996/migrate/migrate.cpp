#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7,INF=0x3f;
int c,t,n,d,x[N],s[N],a[N],dp[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i]=0;
			s[i]=INF;
		}
		s[1]=1;
		for(int i=1;i<=n;i++){
			int j=i-1;
			while(j>=0 && abs(x[i]-x[j])<=d){
				s[i]=min(s[i],s[j]+1);
				j--;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++) a[i]=0;
			a[k]=1;
			for(int i=k;i<=n;i++){
				int j=i-1,sum=0;
				while(j>=k-1 && abs(x[i]-x[j])<=d){
					if(a[j]+1==s[i]-s[k]) sum++;
					a[i]=min(a[i],a[j]+1);
					j--;
				}
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
