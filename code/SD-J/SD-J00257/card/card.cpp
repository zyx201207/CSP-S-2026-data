#include <bits/stdc++.h>
using namespace std;
const int N =5e5 + 10;
int a[N];
int f[300010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(f[a[i]] == 0){
				f[a[i]]++;
			}
			else{
				memset(f,0,sizeof(f))
				f[a[i]]++;
			}
		}
		for(int j = 1;j <= m;j++){
			if(f[j] != 0){
				ans[i]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
} 
