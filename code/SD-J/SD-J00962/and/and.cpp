#include<bits/stdc++.h> // s23261 qwq
//Trick||Treat!
#define int long long
const int N=1e6+10;
using namespace std;
int n,m,a[N],t,ans,mx,q;
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++){
			q=(a[i]&a[i+1]);
		}
		cout<<q;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int f=1;
	for(int i=1;i<=n;i++){
		if(a[i]==n-i) f=1;
	}
	if(f==0){
		cout<<a[m];
		return 0;
	}
	if(f==1){
		int res=a[1];
		for(int i=2;i<=m;i++){
			res=(res&a[i]);
		}
		cout<<res;
		return 0;
	}
	return 0;
}
