#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
const int N=1e6+10,M=1e9+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];
int ans=-INF;
signed main(){
	fst;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				} 
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int res=0; 
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				if(res==0){
					res=a[j];
					continue;
				}
				res&=a[j];
			}
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
}
