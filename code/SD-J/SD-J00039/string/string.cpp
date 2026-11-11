#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],tot,ans;
char c[200005],b[100000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[++tot]=c[i];
		}
	}
	for(int i=1;i<=tot/2;i++){
		if(b[i]!=b[tot-i+1])ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
