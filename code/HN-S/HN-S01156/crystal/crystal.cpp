#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
const int inf=1e18+7;
int n,m;
int a[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	int l=1,r=0;
//	cout<<"!!!m: "<<m<<endl;
	a[0]=a[1];
	while(r<n){
		r++;
		int tmp=(r-l)*(a[r]-a[r-1]);
//		cout<<tmp<<endl;
		m-=tmp;
//		cout<<"m: "<<m<<endl;
		while(m<0){
			m+=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
//		cout<<"l: "<<l<<" r: "<<r<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
