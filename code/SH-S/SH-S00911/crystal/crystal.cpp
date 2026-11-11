#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m; 
int a[500000+10];
int ans; 
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int size=1,sum=0,l=1,r=1;//当前区间左右端点 
	for (int i=2;i<=n;i++) {//要加入的 
		sum+=size*(a[i]-a[r]);//更新新的次数 
		while (sum>m) {
			sum-=a[i]-a[l++];//弹出队头
		}
		r++;//加入队尾
		size=r-l+1;
		ans=max(ans,size);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
