#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int maxn=1e6+7;
int n,m,a[maxn],sum[maxn]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	f(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(i,1,n){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0,l=1;
	f(i,1,n){
		if(sum[i]-sum[l-1]+m>=a[i]*(i-l+1)){
			ans=i-l+1;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}



