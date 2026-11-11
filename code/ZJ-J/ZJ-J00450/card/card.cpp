#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010];
int last_pos[300010];
int ans[500010];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, m;
	bool flag=1;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i-1]>a[i])flag=0;
	}
	
	if(flag){
		for(int i=1;i<=m;i++){
			int pos=upper_bound(a+1,a+n+1,i)-a-1;
			cout << pos << ' ';
		}
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		int cnt=0;
		memset(last_pos,-1,sizeof last_pos);
		for(int j=n;j>=1;j--){
			if(last_pos[a[j]]!=-1)ans[j]=ans[last_pos[a[j]]];
			else ans[j]=(ans[j+1]|(a[j]==i));
			last_pos[a[j]]=j;
			cnt+=ans[j];
		}
		cout << cnt << ' ';
	}
	
	return 0;
}
