#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=5e5+10;

int n,ans;
ll m;
ll a[maxn],s[maxn];

bool solve(int i,int x){
	ll c=1ll*a[i]*(i-x)-(s[i-1]-s[x-1]);
	return c<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}

	ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(solve(i,mid)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}

	cout<<ans;

	return 0;
}
