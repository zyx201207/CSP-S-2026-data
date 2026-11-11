/*我是蒟蒻 wd剪切板没复制全调了我半个小时%%%%%%%%%% 
01背包为什么过不了，只能改爆搜了 
hao xiang shang mi huo xing wei da shang a
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll ans = -1,ans1 = 1;
bool b[2000005];
int a[2000005];
void f(ll cs){
	if(cs > m){
		ans = max(ans,ans1);
		//cout << ans;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(b[i] == 1) continue;
		int j = ans1;
		if(cs == 1) ans1 = a[i]; 
		else ans1 &= a[i];
		b[i] = 1;
		f(cs+1);
		ans1 = j;
		b[i] = 0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		
	}
	f(1);
	cout << ans;
	return 0;
}
