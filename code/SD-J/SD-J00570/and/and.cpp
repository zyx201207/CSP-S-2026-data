#include<bits/stdc++.h>
#define Endl endl
#define endl "\n"
#define For for
using namespace std;
int n,m,arr[200010],max_n = -1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		max_n = max(max_n,arr[i]);
	}
	if(m == 1){
		cout << max_n <<endl;
		return 0;
	}else if(m == n){
		ans = arr[1];
		for(int i = 1;i <= n;i++){
			ans = ans&asrr[i];
		}
		cout << ans <<endl;
		return 0; 
	}
	
	return 0;
} 
