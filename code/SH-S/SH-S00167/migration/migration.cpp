#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j){
				int now=a[i],cnt1=0,cnt2=0;int k1[5010]={0},k2[5010]={0};
				while(now<a[j]){
					now+=d;
					for(int k=i+1;k<=j;++k){
						if(a[k]<=now&&a[k+1]>now){
							now=a[k];++cnt1; k1[k]=1;
							break;
						}
					}
				}
				now=a[j];
				while(now>a[i]){
					now-=d;
					for(int k=j-1;k>=i;--k){
						if(a[k]<=now&&a[k+1]>now){
							now=a[k+1];++cnt2; k2[k]=1;
							break;
						}
					}
				}
				if(cnt2==cnt1){
					bool flag=1,flag1=1;
					for(int k=i;k<=j;++k){
						if(k1[k]==1&&k2[k]==1){
							flag=0;
							break;
						}
						if(k1[k]==1||k2[k]==1) flag1=0;
					}
					if(flag==1) ++ans;
					if(flag1==1) --ans;
				}
			}
		cout<<ans<<endl;
	}
} 
