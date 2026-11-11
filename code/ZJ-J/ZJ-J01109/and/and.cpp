#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200010];
bool f[200010];
struct node {
	int l,r,data;
}tree[800010];
void dfs(int t,int cnt) {
	if (t>n) {
		if (cnt==m) {
			int i,ans=0;
			for (i=1;i<=n;i++)
				if (f[i]) {
					ans=a[i];
					break;
				}
			for (;i<=n;i++) if (f[i]) ans=ans&a[i];
			maxn=max(maxn,ans);
		}
		return ;
	}
	f[t]=true;dfs(t+1,cnt+1);
	f[t]=false;dfs(t+1,cnt);
}
bool cmp(int q,int h) {
	return q>h;
}
void Build(int l,int r,int id) {
	tree[id].l=l;
	tree[id].r=r;
	if (l==r) {
		tree[id].data=a[l];
		return ;
	}
	int mid=(l+r)/2;
	Build(l,mid,id*2);
	Build(mid+1,r,id*2+1);
	tree[id].data=(tree[id*2].data&tree[id*2+1].data);
}
int Check(int l,int r,int id) {
	int t=tree[id].l;
	int w=tree[id].r;
	if (l<=t&&w<=r) return tree[id].data;
	int mid=(t+w)/2;
	int cnt=0,a1=-1,a2=-1;
	if (l<=mid&&mid<=r) cnt++,a1=Check(l,r,id*2);
	if (l<=mid+1&&mid+1<=r) cnt++,a2=Check(l,r,id*2+1);
	if (cnt==2) return (a1&a2);
	else if (cnt==1) return (a1==-1?a2:a1);
	else return -1;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=20) {
		dfs(1,0);
		cout<<maxn;
		return 0;
	}
	if (n==m) {
		maxn=a[1];
		for (int i=2;i<=n;i++) maxn=maxn&a[i];
		cout<<maxn;
		return 0;
	}
	if (m==1) {
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
		return 0;
	}
	if (n<=2000&&m==2) {
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	if (m==n-1) {
		Build(1,n,1);
		maxn=Check(2,n,1);
		for (int i=2;i<n;i++) maxn=max(maxn,Check(1,i-1,1)&Check(i+1,n,1));
		maxn=max(maxn,Check(1,n-1,1));
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	maxn=a[1];
	for (int i=2;i<=m;i++) maxn=maxn&a[i];
	cout<<maxn;
	return 0;
}
