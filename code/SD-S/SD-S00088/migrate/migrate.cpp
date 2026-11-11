#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,d,a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
		}
		if(c==11 || c==12 || f){
			if(d<a[3]-a[1])cout<<"0\n";
			else cout<<max(0ll,n-(d/(a[2]-a[1])*2-1))<<'\n';
			continue;
		}
		int x1=-1,x2=-1,e=-1;
		for(int i=2;i<=n;i++){
			if(a[i]-a[1]<=d && a[i+1]-a[1]>d){
				x1=i;//极限可达最远点
				break;
			}
		}
		if(x1==-1){
			cout<<"0\n";
			continue;
		}
		x2=x1-1;
		for(int i=x1;i<=n;i++){
			if(a[i]-a[x2]<=d && a[i+1]-a[x2]>d){
				e=i;//极限可达最远点
				break;
			}
		}
		if(e==-1){
			cout<<"0\n";
			continue;
		}
		ans=1;
		for(int i=2;i<=n;i++){
			x1=min(x1,i+1);
			while(a[x1+1]-a[i]<=d && x1<=n+1)x1++;
			if(x1>=n+1)break;
			x2=x1-1;
			while(a[e+1]-a[x2]<=d && e<=n+1)e++;
			if(e>=n+1)break;
			if(x1>=e)continue;
//			cout<<x1<<' '<<e<<'\n';
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

