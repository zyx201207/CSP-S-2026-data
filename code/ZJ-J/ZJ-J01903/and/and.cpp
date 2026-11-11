#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int a[maxn];
bool xit[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(m == 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans;
	}else if(m == n){
		int ans = a[1];
		for(int i = 2;i <= n;i++){
			ans= (ans&a[i]);
		}
		cout << ans;
	}else if(m == 2){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				ans =max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
	}else if(m == n-1){
		int ans = 0;
		int mi = 1;
		
		for(int i = 1;i <= n;i++){
			if(a[mi] > a[i])mi = i;
		} 
		bool flaga = true,flagb= true;
		for(int i = 1;i <= n;i++){
			if(a[i] != a[mi]|| a[i] == n){
				ans = a[i];
				break;
			}
		}
		for(int i = 1;i <= n;i++){
			if(i == mi){
				continue;
			}else if(flagb &&  a[i] == ans){
				!flagb;
				continue;
			}else{
				ans = (ans&a[i]);
			}
		}
		cout << ans;
	}else{
		int ans= 0;
		for(int i = 1;i <= m;i++){
			int b = 0;
			for(int j = 1;j <= n;j++){
				if(xit[j] == false&& a[j]  > a[b]){
					b = j;
				}
			}
			xit[b] = true;
			
			if(ans == 0)ans = a[b];
			else ans = (ans&a[b]);
		}
		cout << ans;
	}
	return 0;
}
