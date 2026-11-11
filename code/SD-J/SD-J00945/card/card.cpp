#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
const int N=5e5+10;
int n,m,a[N],ans[N],ids;
vector <int> bot,b(N);
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int k=1;k<=n;k++) {
		b=vector <int> (N);
		for (int i=k;i<=n;i++) {
			for (int j=1;j<=ids;j++) {
				if (b[j]==a[i]) {
					ids=j-1;
					break;
				}
			}
			b[++ids]=a[i];
		}
		for (int i=1;i<=ids;i++) {
			ans[b[i]]++;
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
