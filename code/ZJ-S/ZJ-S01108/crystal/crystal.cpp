#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[500010],b[500010],f[500010];
bool Subtask;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++) f[i]=b[i]=a[i]-a[i-1];
	Subtask=true;
	for (int i=2;i<=n;i++) if (f[i]!=f[i-1]) Subtask=false;
	f[1]=0;
	for (int i=2;i<=n;i++) f[i]=f[i-1]+f[i]*(i-1);
	if (Subtask) {
		for (int i=1;i<=n;i++)
			if (f[i]>m) {
				cout<<i-1;
				return 0;
			}
		cout<<n;
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (f[j]-f[i]-b[j]*(i-1)<=m)
				maxn=max(maxn,(long long)(j-i+1));
	cout<<maxn;
	return 0;
}
