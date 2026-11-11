#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long ans=0;
	for(long long i=1,j=1;i<=n;i++){
		long long sum=s[j-1]-s[i]+a[i]*(i-j+1);
		while(sum>m) sum-=a[i]-a[j],++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	
	return 0;
}
