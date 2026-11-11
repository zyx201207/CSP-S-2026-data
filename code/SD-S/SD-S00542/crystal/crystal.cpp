#include<bits/stdc++.h>
#define ll long long
#define For(i, j, k) for(int i=j;i<=k;i++)
using namespace std;

const int N = 5e5 + 5;
//const int M = ;
int n;
ll d[N], a[N], m;
int calc(int x){
	int L=1,R=x;
	int ans = x;
	while(L<=R){
		int M = L+R>>1;
		if(d[x]-d[M-1]+m>=a[x]*(x-M+1)){
			ans = M;
			R = M-1;
		}else{
//			cout << d[x]-d[M-1]+m << " " << a[x]*(x-M+1) << "\n";
			L = M+1;
		}
	}
//	cout << x << " " << ans << "\n";
//	cout << "\n";
	return ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin >> n >> m;
	For(i, 1, n)cin >> a[i];
	sort(a+1,a+n+1);
	For(i, 1, n)d[i] = d[i-1]+a[i];
//	For(i, 1, n) cout << d[i] << " ";
//	cout << "\n";
	int ans = 1;
	For(i, 2, n){
		ans = max(ans, i-calc(i)+1);
	}
	cout << ans << "\n";
	return 0;
}
