#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[500010];
int m;
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--){
		int nm=m;
		int s=0;
		int x=a[i];
		for(int j=i-1;j>0&&nm>=0;j--){
			nm=nm-(x-a[j]);
			s++;
		}
		ans=max(ans,s-1);
	}
	cout<<ans+1;
	return 0;
}

