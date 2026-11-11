#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,a[N],ans;
char c[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i]>>c[i],m+=a[i];
	int x=0,y=0;
	for (int i=1,j=n; i<=n && i<j; i++){
		x+=a[i];
		while (1){
			int num=min(x-y,a[j]);
			if (c[i]!=c[j]) ans+=num;
			if (x-y<=a[j]) a[j]-=num;
			y+=num;
			if (y==x) break;
			j-=1;
		}
	}
	cout<<ans;
	return 0;
}