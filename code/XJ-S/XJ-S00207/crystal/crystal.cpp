#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=1,maxn=-1;
	for(r=1;r<=n;r++){
		ll pc=a[r]*(r-l+1)-(s[r]-s[l-1]);
		while(pc>m){
			l++;
			pc=a[r]*(r-l+1)-(s[r]-s[l-1]);
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
}
