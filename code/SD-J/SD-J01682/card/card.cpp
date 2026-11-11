#include <bits/stdc++.h>
using namespace std;
int a[500005],m,n,b[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			b[j] = 0;
		}int s = 1;
		for(int j = i;j <= n;j++){
			bool flag = 1;
			int w = 0;
			for(int d = 1;d <= s - 1;d++){
				if(b[d] == a[j]){
					flag = 0;
					w = d;
					break;
				}
			}if(flag){
				b[s] = a[j];
				s++;
			}else{
				for(int d = w;d < s - 1;d++){
					b[d] = 0;
				}s = w;
				b[s] = a[j];
				s++;
			}
		}for(int j = 1;j <= m;j++){
			for(int d = 1;d < s;d++){
				if(b[d] == j){
					ans[j]++;
				}
			}
		}
	}for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}return 0;
}
