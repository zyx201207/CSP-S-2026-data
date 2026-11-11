#include<iostream>
#include<algorithm>
#define N 1000010
using namespace std;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long tk=1,sum=0,cnt=1,ans=1;
	for(int i=2;i<=n;++i){
		sum+=(i-tk)*(a[i]-a[i-1]);
		++cnt;
		while(sum>m){
			sum-=a[i]-a[tk];
			++tk;
			--cnt;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
