#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,m,a[N],f[N];
struct Node {
	int a,x;
};
bool cmp(int x,int y) {
	return x>y;
}
bool cmp1(Node x,Node y) {
	return x.a>y.a;
}
int solve(int step,int ans) {
	if(step==m) return ans;
	Node sum[100]={};int cnt=0;
	for(int i=1;i<=n;i++) {
		if(f[i]==0) {
			++cnt;sum[cnt].a=(ans&a[i]),sum[cnt].x=i;
		}
	}
	sort(sum+1,sum+n+1,cmp1);f[sum[1].x]=1;
	solve(step+1,sum[1].a);
}
int main() {
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;cin>>a[1];int yyj=a[1],tp=1;
	if(yyj!=1) tp=0;
	for(int i=2;i<=n;i++) {
		cin>>a[i],yyj&=a[i];
		if(a[i]!=(int)pow(2,i)) tp=0; 
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) {cout<<a[1];return 0;}
	else if(m==n) {cout<<yyj;return 0;}
	else if(m==2&&n<=5000) {
		int maxn=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j) maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;return 0;
	}
	else if(n<=50) {
		int maxn=0;
		for(int i=1;i<=n;i++) {
			memset(f,0,sizeof f);f[i]=1;
			maxn=max(maxn,solve(1,a[i]));
		}
		cout<<maxn;return 0;
	}
	else if(tp==1) {
		int ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;return 0;
	}
	return 0;
}
