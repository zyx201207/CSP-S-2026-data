//感觉是个01背包板子
//不对 好像要恰好m个？
//先写一个逝世
//9:15
//我先默一遍板子再改
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
//int dp[200005];
void mian1(){
	//#8-#10 n<=2000&&m==2
	int ans=0;
	for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            ans=max(a[i]&a[j],ans);
            //cout << ans << '\n';
        }
	}
	cout << ans;
}
void mian2(){
	//#6 m==1
	int ans=0;
	for(int i = 1;i<=n;i++){
        ans=max(ans,a[i]);
	}
	cout << ans;
}
void mian3(){
	//#7 m==n
	int ans=a[1];
	for(int i = 2;i<=n;i++){
        ans&=a[i];
	}
	cout << ans;
}
//感觉这题初始化难想
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
	if(m==n) mian3();
	else if(m==2)mian1();
	else mian2();
	return 0;
}
//9:20 洋梨2没过
//必须选m个……
//shang cao gao zhi!
/*
5 3
31 3 1 15 7
//10:45 好累 这题难想 我都怕他是个贪心
/*
ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf ccf
*/
//10:47 感觉可以特殊性质拿个15pts
//10:50 100+[0,100]+15=[115,215]
//11:00 100+100+15+0=215
//我靠我靠我T2没加freopen！！！！！！！1
//11:42 100+100+[15,25]+[24,48]=[239,273]
//旁边那哥们野餐呢 又是饼干又是香蕉又是费列罗
