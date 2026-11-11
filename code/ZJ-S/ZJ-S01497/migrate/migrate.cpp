#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010],f[2000010],dist[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[i]=dist[i]=0;
		}
		int ans=0;
		if(c==11||c==12){
			int cha=a[2]-a[1];
			if(2*cha>d)cout<<"0\n";
			else cout<<max(n-d/cha*2+1,0ll)<<"\n";
			continue;
		}
		for(int k=1;k<n-1;k++){
			f[k]=1,dist[k]=0;
			f[k-1]=dist[k-1]=0;
			for(int i=k+1;i<=n;i++){
				if(a[i]-a[k]<=d){
					f[i]=dist[i]=1;
					continue;
				}
				f[i]=0,dist[i]=dist[i-1]+1;
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d){
						dist[i]=min(dist[i],dist[j]+1);
					}
				}
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d&&dist[i]==dist[j]+1){
						f[i]++;
					}
				}
			}
			for(int i=k;i<=n;i++){
				ans+=f[i]==2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
