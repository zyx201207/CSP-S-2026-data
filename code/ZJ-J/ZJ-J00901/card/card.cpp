#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int n,m;
int a[500010],b[300010];
set<int> s;
int main(){
	FIO
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			if(s.count(a[j])){
				int k = i;
				for(k = i;k < j;k ++) 
					if(a[k] == a[j]) break;
				for(;k < j;k ++) s.erase(a[k]);
			}
			s.insert(a[j]);
		}
		for(auto t : s){
			b[t]++;
		}
		s.clear();
	}
	for(int i = 1;i <= m;i ++) cout << b[i] << ' ';
}