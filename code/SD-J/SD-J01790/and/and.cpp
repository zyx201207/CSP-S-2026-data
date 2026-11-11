#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int powed[35];
int a[200007];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	powed[1]=1;
	for(int i=2;i<=31;i++){
		powed[i]=powed[i-1]*2;
	}
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans&=a[i];
	}cout<<ans<<endl;
}
