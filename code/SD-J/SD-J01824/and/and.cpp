#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200002];
int n,k;
bool cmp(int a,int b){
	return a > b;
}
signed main(){
	   freopen("and.in","r",stdin);
	   freopen("and.out","w",stdout);
	   ios::sync_with_stdio(false);
	   cin.tie(0);
	   cout.tie(0);
	   cin >> n >> k;
	   for(int i = 1;i <= n;i ++){
	   		cin >> a[i];
	   }
	   sort(a + 1,a + n + 1,cmp);
	   
	   if(n >= 2000){
		   	int ans = a[1];
		   	for(int i = 2;i <= k;i ++){
		   		ans &= a[i];
		   	}
	   		cout << ans;
	   }
	   else{
	   		int ans = 0;
	   		for(int i = 1;i <= n - k + 1;i ++){
	   			int res = a[i];
	   			for(int j = i;j <= i + k - 1;j ++){
	   				res &= a[j];
				}
				ans = max(ans,res);	
			}
			cout << ans;
	   }
	   return 0;
 }

