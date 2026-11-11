#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn=1;
int a[500005],b[500005],c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=n-1;i>=1;i--) c[i]=b[i]+c[i+1];
	int left=1,right=1,now=1;
	while(right<=n){
		right++;
		m-=now*b[right-1];
		now++;
		if(m>=0){
			maxn=max(maxn,now);
			continue;
		}
		while(m<0){
			m+=c[left]-c[right];
			left++;
			now--;
		}
	}
	cout<<maxn;
	return 0;
}
