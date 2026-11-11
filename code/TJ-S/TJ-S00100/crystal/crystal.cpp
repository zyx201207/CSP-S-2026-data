#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],cnt,maxx,m0;//a,b:原数组，差分
bool Sp = true;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//X X XXX
	//O O OOO 
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i] - a[i-1];
		if(i > 2 and b[i] != b[i-1]) Sp = false;
	}
	sort(a+1,a+n+1);
	if(Sp){
		for(int i = 1;i <= n;i++){
			if(m <= b[2] * (i * (i + 1) / 2) and m < b[2] * ((i+1)*(i+2) / 2)){
				cout << i+1;
				return 0;
			}
		}
	}
	for(int i = 2;i <= n;i++){//选择i作为基准  
		m0 = m;
		cnt = 1;
		for(int j = i - 1;j >= 1;j--){//逆循环让消耗递增,每次都计算一遍 
			int dist = a[i] - a[j];
			if(m0 >= dist){
				m0 -= dist;
				cnt++;
			}
			maxx = max(maxx,cnt);
		}
	}
	cout << maxx;
	return 0;
} 
