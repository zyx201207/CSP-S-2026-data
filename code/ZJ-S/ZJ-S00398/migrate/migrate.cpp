#include<bits/stdc++.h>
using namespace std;
int c,t;long long a[5010];
long long mnp[5010],cnt[5010];
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m;cin>>n>>m;
		if(n>5000){
			cout<<"0"<<endl;
			continue;
		}
		long long ans=0;
		for(i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n;l++){
			memset(mnp,0x7f,sizeof(mnp));
			memset(cnt,0,sizeof(cnt));
			mnp[l]=0;cnt[l]=1;
			for(i=l;i<=n;i++){
				for(j=i-1;j>=l;j--){
					if(a[i]-a[j]>m)break;
					if(mnp[j]+1<mnp[i]){
						mnp[i]=mnp[j]+1;
						cnt[i]=1;
					}else if(mnp[j]+1==mnp[i]){
						cnt[i]+=cnt[j];
					}
				}
				if(cnt[i]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

