//分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++;
#include<bits/stdc++.h>
using namespace std;
int n,m,t1,ccf,ans;
int a[200005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ccf=n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1; i<=n; i++) {
		if(a[i]==a[i+1]) {
			a[i]=0;
			t1++;
			ccf--;
			ans=a[i+1];
		}
	}
	if(t1>=m) {
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int ccf=a[1];
	for(int i=2; i<=m; i++) {
		ccf=(ccf&a[i]);
	}
	cout<<ccf;
	return 0;
}
//分数++; 分数++;  分数++;  分数++;  分数++;  分数++;  分数++;  分数++;  分数++;  分数++;  分数++;  分数++;
