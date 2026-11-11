#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=n;i>=1;i--){
		int cnt=m;
		int res=1;
		for(int j=i-1;j>=1;j--){
			if(cnt<(a[i]-a[j])){
				ans=max(ans,res);
				break;
			}
			res++;
			cnt-=(a[i]-a[j]);
			if(j==1){
				ans=max(ans,res);
			}
		}
	}
	cout<<ans;
	return 0;
}
