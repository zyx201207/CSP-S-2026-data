#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=30;i>=0;i--){
		int x=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1)x++;
		}
		if(x>=m){
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1))a[j]=0;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)continue;
		if(ans==0)ans=a[i];
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
