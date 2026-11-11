#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N],q[N],ans=1;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q[i] = q[i-1]+a[i];
	}
	int l=1,r=1;
	while(l<=r && r<=n){
		r++;
		int cnt = (r-l+1)*a[r];
		long long x=cnt-q[r]+q[l-1];
		while(x > m){
			cnt-=a[r];
			l++;
			x=cnt-q[r]+q[l-1];
		}
		ans = max(ans,(long long)r-l+1);
	}
	cout<<ans;
	return 0;
} 
