#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+10;

int c,t;

int a[maxn],dis[maxn];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) dis[i]=a[i+1]-a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			if(a[i+3]-a[i]<=d) cnt++;
			else if(dis[i]+dis[i+1]+dis[i+2]<=d) cnt++;
			else if(dis[i]<=d && dis[i+1]<=d && dis[i+2]<=d) cnt+=2;
			if(cnt==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
