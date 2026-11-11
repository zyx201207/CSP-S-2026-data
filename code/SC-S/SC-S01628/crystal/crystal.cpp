#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N];
ll s[N];
ll ans=1,maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	
	int opt=1,pto=1;
	for(int i=1;i<=n;i++)
		if(a[i]!=i) opt=0;
	ll sad=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=sad){
			pto=0;
			break;
		}
	if(opt==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum<=m && ans<n)
				ans++;
			else {
				cout<<min(n,ans);
				return 0;
			}
		}
	}
	else if(pto==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*sad;
			if(sum<=m && ans<n)
				ans++;
			else {
				cout<<min(n,ans);
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ll sum=0,maxn=0;
			for(int j=i;j>=1;j--){
				maxn+=a[i]-a[j];
				if(maxn<=m) sum++;
				else break;
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}