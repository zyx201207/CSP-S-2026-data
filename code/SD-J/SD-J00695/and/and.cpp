#include<bits/stdc++.h>
using namespace std;
int a[20000005],n,m;
int main(){//一定删注释，x1y1x2y2是个欸
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=1;i<m;i++){
		ans&=a[n-i];
	}
	cout<<ans;
	return 0;
}

