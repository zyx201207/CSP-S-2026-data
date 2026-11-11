#include<bits/stdc++.h>
using namespace std;
const int N=5*100005;
int n,m;
int a[N],c[N],ans[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		c[i]=a[i]-a[i-1];
	}
	for(int i=1; i<=n; i++) {
		int maxn=-1,num=c[i];
		for(int j=i+1; j<=n; j++) {
			if(num<=m) {

				num+=c[j];
				c[j]+=1;
				maxn=j-i;
			} else break;
		}
		ans[i]=maxn;
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n];
	return 0;
}
