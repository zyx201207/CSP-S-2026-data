//不能用string，数学题
//暴力解17*4=68分
//正解
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,a[N],k,l,r,ans=0;
char c[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		int x;
		char y;
		cin>>x>>y;
		if (c[k]==y) {//合并同类段
			a[k]+=x;
		}
		else {
			a[++k]=x,c[k]=y;
		}
	}
	n=k,l=1,r=n;//更新现在的总段数
	while (l<r) {
		int x1=a[l],x2=a[r];char s1=c[l],s2=c[r];
		if (x1>x2) {
			if (s1!=s2) {
				ans+=x2;
			}
			a[l]-=a[r];
			r--;
		}
		if (x1<x2) {
			if (s1!=s2) {
				ans+=x1;
			}
			a[r]-=a[l];
			l++;
		}
		if (x1==x2) {
			if (s1!=s2) {
				ans+=x1;
			}
			l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
