#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<=a[r])a[r]-=a[l],a[l]=0;
			else a[l]-=a[r],a[r]=0;
		}
		else{
			if(a[l]<=a[r]){
				ans+=a[l];
				a[r]-=a[l];a[l]=0;
			}else{
				ans+=a[r];
				a[l]-=a[r];a[r]=0;
			}
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
/*
Trick||Treat!
*/
