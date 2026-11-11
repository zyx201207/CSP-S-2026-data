#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,res=0;
	ll m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++){
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		} 
		res = max(res,r-l+1);
		cnt+=(r-l+1)*(a[r+1]-a[r]);
	}
	cout<<res;
	return 0;
}
