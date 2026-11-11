#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,ans;
long long a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	c[1]=0;
	long long ll=1;
	long long s=0;
	for(int i=1;i<=n;i++){
		while(s+(i-1-ll+1)*c[i]>m){
			s-=a[i-1]-a[ll];
			ll++;
		}
		s+=(i-1-ll+1)*c[i];
		ans=max(ans,i-ll+1);
	} 
	cout<<ans;
	return 0;
}
//n 5e5 m 0-1e18
//a[i] -1e12-1e12
