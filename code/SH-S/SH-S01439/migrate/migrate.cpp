#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,m,n,a[1000010],ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			if(2*(a[2]-a[1])>m)cout<<0<<endl;
			else cout<<max(ans,n-m/(a[2]-a[1])-m/(a[2]-a[1])+1)<<endl;
			continue;
		}
		if(c==13||c==14){
			int p=0;
			ans=0;
			for(int i=1;i<=n;i++)if(a[i]-a[1]>m){p=i-1;}
			int l=1,r=p+1;
			while(l<p&&r<n){
				while(a[r]-a[l]<=m)r++;
				int y=r;
				while((r<n&&a[r]-a[p-1]<=m&&a[r]-a[p-2]>m&&a[p+1]-a[l]>m)||(a[r]-a[p-1]>m&&a[p+2]-a[l]>m&&a[p+1]-a[l]<=m))
					r++,ans++;
				r=y;l++;
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
