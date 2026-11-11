#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
#define int long long
int n,m,ans;
int a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int r = n,l = n,s = 0;
	while(r >= 1)
	{
		//cout << "当前r为" << r << "开始左移左指针\n";
		while(s <= m && l > 1)
		{
			l--;
			s += a[r]-a[l];
		}
		//cout << "左指针移动完成，位置到" << l << "时s为" << s << '\n';
		ans = max(ans,r-l);
		//cout << "更新答案为" << ans << endl;
		if(s <= m)
		{
			ans = max(ans,r);
			//cout << "在位置" << r << "时前面的所有都可以匹配上，更新答案为" << ans << endl;
			break;
		}
		while(s > m)
		{ 
			r--;
			s -= (r-l+1)*(a[r+1]-a[r]);
			//cout << "r指针左移至" << r << ",s的值变为" << s << '\n';
		}
	}
	cout << ans;
	return 0;
}

