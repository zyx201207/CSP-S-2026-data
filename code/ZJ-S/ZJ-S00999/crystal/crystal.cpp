#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
bool fun(int x){
	int zong=0;
	for(int i=x;i<=n;i++){
		if(i==x){
			for(int j=1;j<=x;j++){
				zong+=a[x]-a[j];
			}if(zong<=m){
				return 1;
			}continue;
		}zong+=(a[i]-a[i-1])*x;
		zong-=a[i]-a[i-x];
		if(zong<=m){
			return 1;
		}
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int l=1,ans=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(fun(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
}
