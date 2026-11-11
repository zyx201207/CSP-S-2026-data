#include <bits/stdc++.h>
using namespace std;
const int N = 500010,M = 300010; 
int n,m,a[N],p[N],vis[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1,j = 1;i <= n;i++){
		cin >> a[i];j = i;
		if(vis[a[i]]){
			j--;
			while(a[j] != a[i]){
				j--;
				vis[a[j]] = 0;
			}
			p[j+1] = 1-j;
			p[i] = 1+j;
		}
		vis[a[i]] = 1;p[j] = 1;
	}
	int tmp = 0;
	for(int i = 1;i <= n;i++){
		tmp += p[i];
		ans[a[i]] = max(ans[a[i]],tmp);
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
} 

