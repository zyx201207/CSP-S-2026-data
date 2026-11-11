#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=2e6+10;
int c,T,a[N];
signed main(){ IOS;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d; cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]-a[1]<=d){
			cout<<0<<endl;
			continue;
		}
		if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) continue;
					int cnt=0,u=i,f2,f=1,cnt1=0,k,sum=1;
					while(u+1<=j){
						k=u;
						f2=1;
						while(k+1<=j&&a[k+1]<=a[u]+d) k++,f2=0;
						if(f2) break;
						u=k; cnt++;
					}
					if(f2) break;
					u=i;
					while(u+1<=j){
						k=u;
						f2=1;
						while(k+1<=j&&a[k+1]<=a[u]+d) k++,f2=0;
						if(f) k--,f=0;
						if(f2||k<u) break;
						u=k; cnt1++; 
					}
					if(f2) break;
					if(cnt1==cnt) sum++;
					u=i;
					cnt1=0; f=1;
					while(u+1<=j){
						k=u;
						f2=1;
						while(k+1<=j&&a[k+1]<=a[u]+d) k++,f2=0;
						if(f) k-=2,f=0;
						if(f2||k<u) break;
						u=k; cnt1++;
					}
					if(f2) break;
					if(cnt1==cnt) sum++;
					if(sum==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}