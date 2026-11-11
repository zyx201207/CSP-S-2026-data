#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,m,a[N];

bool cmp (int a,int b){
	return a>b;
}

signed main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort (a+1,a+n+1,cmp);
	
	int ans=0;
	for (int i=30;i>=0;i--){
		int can=0;
		
		for (int j=1;j<=n;j++){
			if (( a[j]%(1<<(i+1)) ) / (1<<i) == 1){
				can++;
			}
			else if ((can>=m) && ( a[j]%(1<<(i+1)) ) / (1<<i) == 0){
				a[j]=0;
			}
		}
		if (can>=m) {
			ans+=(1<<i);
		}
	}
	cout << ans;
	return 0;
}
