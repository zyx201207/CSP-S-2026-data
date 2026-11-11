#include <bits/stdc++.h>
using namespace std;
long long n,t,w,ans,Subtask;
long long a[200010];
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
	t=1;w=n;
	while (t<w) {
		if (c[t]!=c[w]) {
			if (a[t]>=a[w]) {
				ans+=a[w];
				a[t]-=a[w];
				w--;
			}
			else {
				ans+=a[t];
				a[w]-=a[t];
				t++;
			}
		}
		else {
			if (a[t]>=a[w]) {
				a[t]-=a[w];
				w--;
			}
			else {
				a[w]-=a[t];
				t++;
			}
		}
	}
	cout<<ans;
	return 0;
}
