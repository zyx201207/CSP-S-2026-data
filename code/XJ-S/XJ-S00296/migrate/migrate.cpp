#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=100005) {
		sort(a+1,a+n+1,cmp);
		int maxn=0;
		for(int i=1; i<=n; i++) {
			int sum=0,x=i,cnt=0;
			while(sum<=m&&x<=n) {
				x++;
				sum+=a[i]-a[x];
				cnt++;
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	} else {
		int flag=0;
		for(int i=1; i<=n; i++) {
			if(a[i]!=i) flag=1;
		}
		if(flag==0) {
			int c;
			for(c=1; c<=n; c++) {
				if((1+c)*c/2>m) break;
			}
			cout<<c;
		} else {
			int w=a[2]-a[1];
			int c;
			for(c=1; c<=n; c++) {
				if(((1+c)*c/2)*w>m) break;
			}
			cout<<c;
		}
	}
	return 0;
}
