#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],num[500010];
deque <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1 ; i<=n ; i++) cin >> a[i];
	for (int i=1 ; i<=n ; i++){
		int len;
		map<int,int> mp;
		for (int j=i ; j<=n ; j++){
			if (mp[a[j]]!=0){
				while (q.back()!=a[j]){
					mp[q.back()]=0;
					q.pop_back();
					len--;
				}
				mp[q.back()]=0;
				q.pop_back();
				len--;
			}
			q.push_back(a[j]);
			mp[a[j]]=len+1;
		}
		while (!q.empty()){
			if (q.front()>=1 && q.front()<=m) num[q.front()]++;
			q.pop_front();
		}
	}
	for (int i=1 ; i<=m ; i++) cout << num[i] << " ";
	return 0;
}
