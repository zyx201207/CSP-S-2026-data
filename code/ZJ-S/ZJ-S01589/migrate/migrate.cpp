#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,D,ans=0;
 int a[500010];
 int ds[500010],sm[500010];
void calc(int x){
	for(int i=x+1;i<=n;i++)ds[i]=1e18;
	for(int i=x+1;i<=n;i++)sm[i]=0;
	ds[x]=0;
	sm[x]=1;
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>D)break;
			if(ds[j]>ds[i]+1){
				ds[j]=ds[i]+1;
				sm[j]=sm[i];
			}else if(ds[j]==ds[i]+1)sm[j]+=sm[i];
		}
		if(sm[i]==2)ans++;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	cin>>_;
	while(_--){
		cin>>n>>D;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		int mn=1e18;
		for(int i=2;i<=n;i++)mn=min(mn,a[i]-a[i-1]);
		if(mn*2>D){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)calc(i);
		cout<<ans<<"\n";
	}
	return 0;
}