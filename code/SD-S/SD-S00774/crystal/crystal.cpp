#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=0;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=1,sum=0;
	while(l<=n&&r<=n){
		sum+=a[l]-a[r];
		while(sum>m){
			sum=sum-(r-l)*(a[l]-a[l+1]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
