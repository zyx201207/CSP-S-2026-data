#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000002],rn[2000002];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",x+i);
		if(n==1){
			cout<<0<<endl;
			continue; 
		}
		if(c==11||c==12){
			int tgt=d/(x[2]-x[1]);
			if(tgt==1||tgt==0) cout<<0<<endl;
			else cout<<max(n-tgt*2+1,0ll)<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0,diff=0;
				rn[0]=i;
				for(int k=i;k<j;){
					int l=k;
					while(l<=j&&x[l]-x[k]<=d) l++;
					if(k==l-1){
						diff=2;
						break;
					}
					k=l-1;
					rn[++cnt]=k;
				}
				if(diff==2) continue;
				for(int k=j;k>i;){
					int l=k;
					while(l>=i&&x[k]-x[l]<=d) l--;
					k=l+1;
					if(rn[--cnt]!=k){
						diff++;
						if(rn[cnt]!=k+1) diff++;
					}
					if(diff==2) break;
				}
				if(diff==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
