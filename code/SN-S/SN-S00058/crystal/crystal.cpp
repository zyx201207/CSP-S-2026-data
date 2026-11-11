#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
//const long long INF = -1e18;
long long n,m;
long long a[maxn];
long long l,r;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	l=1;
	r=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		r=i;
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,(r-l+1));
	}
	cout<<ans<<endl; 
	return 0;
}
