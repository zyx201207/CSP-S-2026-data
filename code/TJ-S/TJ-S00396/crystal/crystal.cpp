#include<bits/stdc++.h>
using namespace std;
namespace alldef{
	#define int long long
	#define N 500005
}
using namespace alldef;
namespace init{
	int n,m;
	int a[N];
}
using namespace init;
namespace lochren{
	void solve(){
		int mx=0;
		int l=1,r=l+1;
		int mid=a[r];
		int sum=0,ans=0;
		for(;sum<=m;){
			if(sum+abs(mid-a[l])<=m and l>=1){
				sum+=abs(mid-a[l]);
				ans++;
			}
			else{
				if(ans+1>=mx){
					mx=ans+1;
				} 
				else break;
				if(mid+1<=n){
					int tmp=r+1;
					mid=a[tmp];
					l=r;
					r++;
					ans=0;
					sum=0;
					continue;
				}
				else break;
			}
			l--;
		}
		cout<<mx;
	}
}
using namespace lochren;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	solve(); 
	return 0;
} 
