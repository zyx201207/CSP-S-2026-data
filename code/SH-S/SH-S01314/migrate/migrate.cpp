#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000020],y[2000020];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			y[i]=0;
		}
		for(int i=1;i<n;i++){
			int r=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
			for(int j=i+1;j<=r;j++) {
				if(!y[j]) y[j]=y[i]+1;
			}
			if(r==n) break;
		}
		int ans=0;
		for(int i=1;i<=n-3;i++) {
			if(y[i+2]-y[i]==1&&y[i+3]-y[i+1]==1) {
				int l=i,r=i+3,cnt1=0,cnt2=0;
				while(l>2) {
					if(y[l]-y[l-1]==1) {
						l--;
						cnt1++;
					}
					else break;
				}
				if(l==2) {
					cnt1+=(y[3]-y[2]);
				}
				while(r<n) {
					if(y[r+1]-y[r]==1){
						r++;
						cnt2++;
					}
					else break;
				}
				ans+=(cnt1+1)*(cnt2+1);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

