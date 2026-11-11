#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
constexpr int N=5e5+5;
int a[N],n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cost=0,ans=0;
	for(int i=1,j=1;i<=n;i++){
		cost+=(i-j)*(a[i]-a[i-1]);
		while(j<=i&&cost>m){
			j++;
			cost-=a[i]-a[j-1];
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}