#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[2000010];

ll dfs(int l,int r,int c,ll d){
	if(c==1) return (a[r]-a[l]<=d);
	if(l>r) return 0;
	int i;
	ll ans=0;
	for(i=l+1;a[i]-a[l]<=d&&i<=r;i++){
		ans+=dfs(i,r,c-1,d);
	}
	//if(ans==2) printf("dfs(l=%d,r=%d,c=%d,d=%d)=%lld\n",l,r,c,d,ans);
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,_;cin>>cc>>_;
	while(_--){
		int n;ll d;cin>>n>>d;
		int i,j,k;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0;
		for(i=1;i<=n;i++){
			for(j=i+2;j<=n;j++){
				int c=1,lst=i;
				for(k=i;k<=j;k++){
					if(a[k]-a[lst]>d){
						lst=k-1;
						c++;
					}
				}
				if(dfs(i,j,c,d)==2){
					//printf("[%d,%d]\n",i,j);
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

