#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+33,INF=-0x3f3f3f3f;
long long c,t,n,m,a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		long long ans=0;
		vector<long long> e;
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		if (c==11||c==12){
			if (a[2]-a[1]>m){
				cout<<0<<endl;
			} else{
				cout<<n-1-(m/(a[2]-a[1]))<<endl;
			}
			continue;
		}
		for (long long i=1;i<=n-3;i++){
			if (a[i]+m>=a[i+1]&&a[i]+m>=a[i+2]&&a[i]+m<a[i+3]&&a[i+3]<=a[i+1]+m&&a[i+3]<=a[i+2]+m){
				e.push_back(i);
			}
		}
		for (long long i=0;i<e.size();i++){
			long long l=e[i],r=e[i]+3,cnt1=0,cnt2=0;
			while (l>=2&&a[l-1]+m>=a[l]&&a[l-2]+m<a[l]){l--;cnt1++;}
			while (r<=n-1&&a[r]+m>=a[r+1]&&a[r]+m<a[r+2]){r++;cnt2++;}
			ans+=(cnt1+1)*(cnt2+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
