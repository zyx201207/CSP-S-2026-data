#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,maxn=1;
	long long m,k;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) b[i]=a[i];
	for (int i=1;i<=n;i++) b[i]=b[i]+b[i-1];
	
	k=a[1]-1;
	for (int i=n;i>=maxn;i--){
		if (a[i]==k) continue;
		k=a[i];
		for (int j=i-1;j>=0;j--){
			if (a[i]*(i-j)-b[i]+b[j]>m) break;
			maxn=max(maxn,i-j);
		}
	}
	cout << maxn;
	return 0;
}
