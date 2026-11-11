#include<bits/stdc++.h>
using namespace std;

int ans[50010];
int a[50010];
int c[50010];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 500){
		for(int l = 1;l <= n;l++){
			for(int i = l;i <= n;i++){
				if(c[a[i]] == 1){
					for(int j = i - 1;j >= l;j--){
						if(a[j] != a[i]){
							c[a[j]] = 0;
						}else{
							break;
						}
					}
				}else{
					c[a[i]] = 1;
				}
			}
			for(int i = 1;i <= m;i++){
				ans[i] += c[i];
				c[i] = 0;
			}
		}
		for(int i = 1;i <= m;i++){
			cout << ans[i] << ' ';
		}
	}else{
		for(int l = 1;l <= n;l++){
			for(int i = l;i <= n;i++){
				c[a[i]] = 1;
			}
			for(int i = 1;i <= m;i++){
				ans[i] += c[i];
				c[i] = 0;
			}
		}
		for(int i = 1;i <= m;i++){
			cout << a[i] << ' ';
		}
	}
}
