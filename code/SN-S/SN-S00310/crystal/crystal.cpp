#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxn=-1;
	for(int i=1;i<=n;i++){
		int k=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(k>=a[i]-a[j]){
				cnt++;
				k-=(a[i]-a[j]);
			}else break;
		}
		if(cnt>maxn)maxn=cnt;
	}
	cout<<maxn;
	return 0;
}
