#include<bits/stdc++.h>
using namespace std;
#define testid string("")
#define filei freopen(("crystal"+testid+".in").c_str(), "r", stdin)
#define fileo freopen("crystal.out", "w", stdout)
#define int long long
int fuck[500050];
int a[500050];
// 8 7 8 2 5 8 8 -3 -5 
signed main(){
	 filei;
	fileo;
	int n; cin >> n;
	int m;
	cin>>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a+1, a+n+1);
	int fucking = a[1];
	for(int i=1;i<=n;i++) {
		a[i]-=fucking;
		fuck[i]=fuck[i-1]+a[i];	 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int L = 1, R = i;
		while(L<R){
			int mid=L+R>>1;
			int need = (i-mid+1)*a[i] + fuck[mid-1] - fuck[i];
			if(need<=m){
				R=mid;
			}else{
				L=mid+1;
			}
		}
		
		ans=max(i-L+1, ans);
//		cout << i-L+1 << endl;
	}
	cout << ans << endl;
}