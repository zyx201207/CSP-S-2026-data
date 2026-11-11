#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010;
int n,m;
bool flag;
int a[N],rk[N],ans[N],t[N],d[N];
vector<int> g[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i],
		g[a[i]].push_back(i),
		rk[i] = g[a[i]].size() - 1;
		if(a[i] < a[i - 1]) flag = 1;
	}
	if(!flag){
		d[a[1]] ++,d[m + 1] --;
		int lst = a[1];
		for(int i = 2 ; i <= n ; i ++){
			if(a[i] != lst) lst = a[i];
			d[lst] ++,d[m + 1] --;
		}
		int sum = 0;
		for(int i = 1 ; i <= m ; i ++){
			sum += d[i];
			cout << sum << ' ';
		}
		return 0;
	}
	for(int i = n - 1 ; i >= 1 ; i --){
		int L = i,R = n;
		memset(t,0,sizeof(t));
		for(int j = L ; j <= R ; j ++){
			int p = a[j];
			t[p] ++;
		}
		for(int i = 1 ; i <= m ; i ++)
			if(t[i]) ans[i] ++;
	}
	for(int i = 1 ; i <= m ; i ++)
		cout << ans[i] << ' ';
	return 0;
}
//RP ++
//Luogu @zzhengxi
