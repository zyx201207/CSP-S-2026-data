#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;

int a[N],box[N],ans[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	stack<int> z;
	for (int i = 1;i <= n;i++){
		memset(box,0,sizeof(box));
		while(z.size()){
			z.pop(); 
		}
		for (int j = i;j <= n;j++){
			if (box[a[j]] == 0){
				z.push(a[j]);
				box[a[j]] ++;
			}
			else{
				while(z.size()){
					if (z.top() == a[j]){
						break;
					}
					box[z.top()]--;
					z.pop();
				} 
			}
		}
		for (int j = 1;j <= m;j++){
			ans[j] += box[j]; 
		}
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}

