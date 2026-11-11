#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;

int n;
ll m;//1e18 
ll a[N];//每个水晶的能量 
int ma = 0;
int f(int x){
	int i = x-1;//第i个水晶 
	ll y = m;//剩余操作次数 
	int cnt = 1;//记录相同水晶个数 
	while (i>=1){
		if (a[i]+y>=a[x]){
			y -= a[x]-a[i];
			cnt ++;
			i --;
		}else break;
	}
	return cnt;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(a+1,a+n+1);
	if (n < 5010){
		for (int i = 1;i <= n;i ++){
			int x = f(i); 
			ma = max(ma,x);
		}
		
		cout << ma;
	}else{
		int cha = a[1]-a[0];
		int cnt = 0;
		for (int i = 1;m > 0;i ++){
			int cut = cha*i;
			if (m >= cha) cnt ++;
			m -= cut;
		} 
		cout << cnt << endl;
	}
	
	
	return 0;
} 