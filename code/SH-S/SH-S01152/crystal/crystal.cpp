#include <bits/stdc++.h>
using namespace std;
const int N=500009;
long long n,m,a[N],s[N];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int r=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-r+1)-(s[i]-s[r-1])>m){
			r++;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<'\n';
	return 0;
} 
