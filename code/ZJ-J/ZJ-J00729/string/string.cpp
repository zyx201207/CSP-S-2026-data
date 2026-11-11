#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l,r,MIN;
long long s;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>c[i];
	l=1;r=n;
	while(l<r){
		MIN=min(a[l],a[r]);
		a[l]-=MIN;a[r]-=MIN;
		if(c[l]!=c[r])s+=MIN;
		if(!a[l])++l;if(!a[r])--r;
	}
	cout<<s<<"\n";
	return 0;
}
