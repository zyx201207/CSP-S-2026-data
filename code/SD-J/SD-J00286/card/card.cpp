#include <bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010];
bool jy[300010];
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}for(int i = 1;i <= n;i++){
		fill(jy,jy+300010,0);
		for(int j = i;j<=n;j++){
			if(jy[a[j]] == 1){
				while(1){
					int aa = q.back();
					q.pop_back();
					if(aa == a[j]){
						break;
					}
				}
			}
			q.push_back(a[j]);
			jy[a[j]] = 1;
		}
		while(1){
			int aa = q.back();
			q.pop_back();
			ans[aa]++;
			if(q.empty()){
				break;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
