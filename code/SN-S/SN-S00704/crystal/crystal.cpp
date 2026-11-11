#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,mx=-1e9,mn=1e9;
int a[N],ans=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int sum=1,mm=m;
		for(int j=i-1;j>=1;j--){
			if(mm>=a[i]-a[j]){
				mm-=(a[i]-a[j]);
				sum++;
			}else break;
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
