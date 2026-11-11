#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10; 
int n,m;
int a[N] = {},ans[N] = {};
int f[N] = {};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int x = 1;x <= n;x++){
		int c[N] = {},l = 0;
		for(int i = x;i <= n;i++){
			if(f[a[i]] == 0){
				l++;
				c[l] = a[i];
				f[c[l]] = 1;
			}else{
				while(c[l] != a[i]){
					f[c[l]] = 0;
					c[l] = 0;
					l--;
				}
			}
		}
		for(int i = 1;i <= m;i++){
			if(f[i] != 0){
				ans[i]++;
				f[i] = 0;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
