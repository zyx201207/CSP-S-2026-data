#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,s,maxx;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=1,le=0;
	for (int i = 1;i <= n;i++){
		int need;
		need=(a[i]-a[i-1])*le;
		s+=need;
		if (s<=m){
			ans++;
			le++;
		}else{
			ans++;
			le++;
			while(s>m){
				ans--;
				int jian;
				jian=a[i]-a[l];
				le--;
				s-=jian;
				l++;
			}
		}
		maxx=max(maxx,ans);
	}
	cout << maxx;
	return 0;
}
//1 2 4 8  9
//0 1 4 12 4
//0 1 5 17 21


//5 8
//-3 -1 2 2 7

//5 5
//1 2 4 8 9