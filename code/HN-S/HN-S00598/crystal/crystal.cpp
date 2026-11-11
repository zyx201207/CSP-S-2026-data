#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+50;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,ans=0;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long x=1;
	for(long long j=1;j<=n;j++){
		sum+=b[j]*(j-x);
		if(sum>m){
			ans=max(ans,j-x);
			while(sum>m){
				sum-=a[j]-a[x];
				x++;
			}
		}
	}
	ans=max(ans,n-x+1);
	cout << ans << endl;
}

