#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,m;
long long a[N];
long long pre[N];
long long ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		pre[i] = pre[i-1] + a[i];
	}
	for(int i = 1;i<=n;i++){
		long long l = 0,r = i;
		long long cnt = 1e10;
		while(l<=r)
		{
			long long mid = (l+r)/2;
			if(pre[mid]-a[i]*mid<=m+pre[i]-a[i]*i){
				cnt = min(cnt,mid);
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		ans = max(ans,i-cnt);
	}
	cout<<ans<<endl;
	return 0;
} 
