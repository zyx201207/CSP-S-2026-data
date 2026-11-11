#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int arr[N],n,m,p[31],cnt[31],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0] = 1;
	for (int i = 1;i<=30;i++)p[i] = p[i-1]*2;
	cin>>n>>m;
	for (int i = 1;i<=n;i++)cin>>arr[i];
	while (1) {
		memset(cnt,0,sizeof cnt);
		for (int i = 1;i<=n;i++) {
			int k = arr[i];
			for (int i = 30;i>=0&&k;i--)if (k>=p[i])k-=p[i],cnt[i]++;
		}
		int line = -1;
		for (int i = 30;i>=0;i--) {if (cnt[i]>=m) {line = i;break;}}
		if (line==-1)break;
		int j = 0;
		for (int i = 1;i<=n;i++) {
			if (arr[i]%p[line+1]>=p[line])swap(arr[i],arr[++j]),arr[j]-=p[line];
		}
		n = j,ans+=p[line];
	}
	cout<<ans;
	return 0;
}
