#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],c[500010],last;
bool check(int x){
	for(int i = x;i <= n;i++) if((x - 1) * a[i] - (c[i - 1] - c[i - x]) <= m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int cnt = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)c[i] = c[i - 1] + a[i];
	int l = 1,r = n,ans = 1;
	int mid = (l + r) / 2;
	while(l < r){
		//cout << l << " " << mid << " " << r << endl;
		mid = (l + r) / 2;
		if(check(mid)){
			ans = max(ans,mid);
			l = mid;
		}
		else{
			r = mid;
		}
		if(last == ans)cnt++;
		last = ans;
		if(cnt > 20)break;
	}
	cout << ans;
	return 0;
}

///*
//哈吉米莫南北绿豆 
//阿西嘎哈呀库奶露 
//bro 的 CSPS游记:
//14:18 我去?我早上居然没有//freopen,太强了ovo 
//突然想到初赛时记兄弟的身份证了hhh(开户成功)
//15:21 666T1想到二分答案了，不知道check函数咋写(悲) 
//16:12 wow吾居然把check写出来了，但是只过了小数据 
//17:00 竟然是二分边界的问题多跑几次就对了acT1? 
//
//*/

