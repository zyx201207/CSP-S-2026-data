#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,a[N],ans;
char b[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<j){
		int x=min(a[i],a[j]);
		if(b[i]!=b[j])ans+=x;
		a[i]-=x,a[j]-=x;
		if(!a[i])++i;
		if(!a[j])--j;
	}
	cout<<ans;
	return 0;
}
