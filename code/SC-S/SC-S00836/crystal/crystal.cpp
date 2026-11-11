#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],cf[N],ans=0;
bool cmp(int &a,int &b){
	return a<b;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		cf[i]=a[i]-a[i-1];
	}
	for(int i=1; i<=n-ans; i++) {
		int ls=0;
		for(int j=1;;j++){
			ls+=cf[i+j]*j;
			if(ls>m){
				ans=max(ans,j);
			//	cout<<"["<<i<<"]["<<j<<"]ans="<<ans<<endl;
				break;
			}
			if(j==n-i){
				ans=max(ans,j+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}