#include<bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long
using namespace std;
const int N=5e5+10;
long long a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=1;
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]-a[i-1]==1&&a[1]==1&&f==1) f=1;
		else f=0;
	}
	if(n<=5000){
		long long maxn=-0x3f3f;
		ll d=m;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			long long ans=0;
			m=d;
			for(int j=i+1;j<=n;j++){
				if(a[i]-a[j]<=m){
					m-=(a[i]-a[j]);
					ans++;
				}else{
					maxn=max(maxn,ans);
					break;
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn+1;
	}else if(f==1){
		for(ll i=1e4;i<=1e9;i++){
			if((1+i)*i/2>=m){
				cout<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
