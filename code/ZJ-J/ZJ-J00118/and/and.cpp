#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
