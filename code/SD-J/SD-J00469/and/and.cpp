#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int maxn = -1;
const int N = 1e6+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == m){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans = ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	ans = a[1];
	for(int i = 2;i <= m;i++){
		ans = ans&a[i];
	}
	cout<<ans;
	return 0;
}
