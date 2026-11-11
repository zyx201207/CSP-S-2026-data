#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m,a[N],ans=0,maxn=0;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,abs(a[i]));
		if(a[i]!=i) f=0;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ll cnt=1,M=m;
			for(int j=i-1;j>=1;j--){
				if(M>=a[i]-a[j]){
					M-=(a[i]-a[j]);
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(maxn<=100){
		for(int i=a[1];i<=a[n];i++){
			ll cnt=0,M=m;
			int t=upper_bound(a+1,a+n+1,i)-a;
			t-=1;
			for(int j=t;j>=1;j--){
				if(M>=i-a[j]){
					M-=(i-a[j]);
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<'\n';
		return 0;
	}
/*	if(f==1){
		ll M=m;
		for(int i=1;i<=n;i++){
			if(M-(i-1)>=0){
				M-=(i-1);
			}
			else{
				cout<<i-1<<'\n';
				return 0;
			}
		}
		cout<<n<<'\n';
		return 0;
	}*/
	ll M=m,dis=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(M-(i-1)*dis>=0){
			M-=(i-1)*dis;
		}
		else{
			cout<<i-1<<'\n';
			return 0;
		}
	}
	cout<<n<<'\n';
	return 0; 
}
