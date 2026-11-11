#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N=5e5 + 5;
int a[N],pre[N];
int n,m;
int query(int l,int r){
	return pre[r] - pre[l] - (l - 1) *(a[r] - a[l]);
}
bool check(int r,int x){
	int l=r - x + 1;
	return query(l,r) <= m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i=1;i <= n;i++){
		pre[i]=pre[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	int mx=0;
	for(int i=2;i <= n;i++){
		int l=1,r=i,mid,ans;
		while(l <= r){
			mid=l + (r - l) / 2;
			if(check(i,mid)){
				ans=mid;
				l=mid + 1;
			} else{
				r=mid - 1;
			}
		}
		mx=max(mx,ans);
	}
	cout << mx;
	return 0;
}