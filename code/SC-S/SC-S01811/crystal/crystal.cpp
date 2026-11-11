#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500005],cnt;


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]<a[l+1]-a[l])l=i;
	}
	int r=l;
	while(cnt<m){
		if(((r-l+1)*(a[r+1]-a[r])<a[r]-a[l-1]&&r<n)||(l<=1&&r<n)){
			cnt+=(r-l+1)*(a[r+1]-a[r]);
			if(cnt>m)break;
			r++;
		}else if(l>1){
			cnt+=a[r]-a[l-1];
			if(cnt>m)break;
			l--;
		}else break;
	}
	cout<<r-l+1;
	return 0;
}