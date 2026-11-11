#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
set<int> st;
int a[500005];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int flag=0, te;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==2){
			te=a[i]-a[1];
		}else if(i>2){
			if(te!=a[i]-a[i-1]){
				flag=1;
			}
		}
	}
//	cout << te << " " << flag << " ";
	if(flag==0){//特殊性质a，b 
		te=abs(te); 
		int o=(long long)sqrt(m*2/te);
		while(o*(o+1)*te>m && o) o--;
		cout << o+1;
	}else if(n<=10000){
		int maxn=0;
		sort(a+1, a+n+1);
		for(int i=1;i<=n;i++){
			int j=i-1, mn=m, ans=0;
			while(mn>=0 && j>=0){
				mn-=(a[i]-a[j]);
				j--;
				ans++;
	//			cout << mn << "\n";
			}
	//		cout << "\n";
			maxn=max(maxn, ans);
		}
		cout << maxn;
	}else{
		int maxn=0;
		sort(a+1, a+n+1);
		cout << 1;
		for(int i=n;i>=1;i--){
			int j=i-1, mn=m, ans=0;
			while(mn>=0 && j>=0){
				mn-=(a[i]-a[j]);
				j--;
				ans++;
	//			cout << mn << "\n";
			}
	//		cout << "\n";
			maxn=max(maxn, ans);
			if(maxn==n) break;
		}
		cout << maxn;
	}
	return 0;
} 
// 14:50 二分（未考虑顺序）+前缀和失败 
// 15:13 拿下45分 
// 15:36 拿下特殊性质A, B。拿下约75分
// 15:40 发现错误 
// 16:07 错误解决，并加以骗分，这波牛大了，时间分配较为不合理 
// 17:20 骗分，颓了已经  
// 18:25 想上行为大赏 
