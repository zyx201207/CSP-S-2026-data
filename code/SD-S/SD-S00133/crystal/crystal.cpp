#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=1,m1=m,i1=1;
	while(m1>=cnt*(a[i1+1]-a[i1])&&i1<=n){
		m1-=cnt*(a[i1+1]-a[i1]);
		cnt++;
		i1++;
	}
	ans=max(ans,cnt);
	for(int i=2;i<=n;i++){
		cnt--;
		m1+=(a[i1]-a[i-1]);
		while(m1>=cnt*(a[i1+1]-a[i1])&&i1<=n){
			m1-=cnt*(a[i1+1]-a[i1]);
			cnt++;
			i1++;
		}
		ans=max(ans,cnt);
		if(ans==n){
			break;
		}
	}
	cout<<ans;
	return 0;
}
