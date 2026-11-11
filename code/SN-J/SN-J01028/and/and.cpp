#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long n,a[MAXN],m,maxx=-1,tk=0,dk=0,ans=0,cnt=0;
bool aj[35][MAXN];
void doo(int x,int k) {
	int h=1;
	while(x) {
		aj[h][k]=(bool)(x%2);
		x/=2;
		h++;
	}
	return;
}
int work(int x) {
	int ans=0;
	while(x) {
		x/=2;
		ans++;
	}
	return ans;
}
bool cmp(int ak1,int ak2) {
	return ak1>ak2;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxx=max(a[i],maxx);
		doo(a[i],i);
	}
	tk=work(maxx);
	for(int i=tk; i>=0; i--) {
		int cnt=0;
		for(int j=1; j<=n; j++) {
			if(aj[i][j]) {
				cnt++;
			}
		}
		if(cnt>=m) {
			dk=i;
			break;
		}
	}			
	for(int i=1; i<=n; i++) {
		int ts=work(a[i]);
		if(ts>dk) {
			a[i]=(a[i]>>(ts-dk));
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1; i<=m; i++) {
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

