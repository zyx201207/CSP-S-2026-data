#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1;
	long long s=0;
	long long ans=1;
	for(int i=2;i<=n;i++){
		s+=(i-l)*(a[i]-a[i-1]);
		while(s>m){
			s-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
