/*
居然没有串串 
那你的 Manacher 下放到 S 干啥  
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+10;
int n,m;
int a[N];
int sum;
int p=1;
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++){
		while ((i-p)*a[i]-sum>m&&p<i){
			sum-=a[p];
			++p;
		}
		sum+=a[i];
		ans=max(ans,(i-p+1));
	}
	cout<<ans;
	return 0;
}

