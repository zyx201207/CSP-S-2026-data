#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn];
int ans;
int n,m;
int yu[maxn];
void f(int dep,int sum,int num){
	if (num==m){
		ans=max(ans,sum);
	}
	if (dep==n+1||num>m)return;
	f(dep+1,sum,num);
	if (num==0)f(dep+1,a[dep],num+1);
	else f(dep+1,sum&a[dep],num+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	} 	
	f(1,0,0);
	cout << ans;
	return 0;
}
