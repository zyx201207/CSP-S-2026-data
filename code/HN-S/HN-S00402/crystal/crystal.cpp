#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long d[N];
long long ans;

void solve(){
	long long r=1;
	for(int i=1;i<=n;i++){
		long long l=i;
		while(r<=n&&(d[r]-d[l-1]+m)/(r-l+1)>=a[r]){
			r++;
		}
		ans=max(ans,r-l);
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	solve();
	cout<<ans;
	return 0;
}
