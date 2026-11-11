#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=5e5+5;
int n,m,a[mcx],ma=LLONG_MIN;
int d=0,f=1;
class SUBAB{
public:
	void work(){
		int need=m/d,i=1;
		while(((i+1)*(i+2)/2)<=need){
			i++;
		}
		cout<<i+1<<'\n';
	}
}AB;//30
class SUBFF{
public:
	void work(){
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0,cnt=0;
			for(int j=i;j>=1;j--){
				if(sum+a[i]-a[j]>m)break;
				sum+=(a[i]-a[j]);
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<'\n';
	}
}FF;//45
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];ma=max(ma,abs(a[i]));
		if(i==2)d=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=d)f=0;
	}
	sort(a+1,a+n+1);
	if(f){
		AB.work();
		return 0;
	}
	else{
		if(2*ma*n<=m){
			cout<<n<<'\n';
			return 0;
		}
		if(n<=5000){
			FF.work();
			return 0;
		}
	}
	return 0;
}
