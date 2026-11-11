#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
const int M = 3e5+10;
int n,m,ans[M];
int a[N],cnt[M],last[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.ont","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		last[a[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		int y = 0;
		cnt[a[i-1]]--;
		for(int j = i;j <= n;j++){
			if(cnt[a[j]] % 2 == 1){
				ans[a[j]]++;
				y = 1;
			}
			else{
				break;
			}
		}
		for(int j = n;j >= i;j--){
			if(cnt[a[j]] % 2 == 1 && y == 0){
				ans[a[j]]++;
			}
			else{
				break;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
