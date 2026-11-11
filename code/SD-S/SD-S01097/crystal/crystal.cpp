#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+10;
int n;ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;ull sum=0;
	for(int i=1,j=1;i<=n;i++){
		if(i!=1) sum-=a[j]-a[i-1];
		while(j<=n&&sum<=m) ans=max(ans,j-i+1),sum+=(a[j+1]-a[j])*(j-i+1),j++;
	}
	cout<<ans;
	return 0;
}
