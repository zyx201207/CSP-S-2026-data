#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[5000005];
bool f=1;
bool g(int h){
	if(f==0){
		for(int i=h;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=i;j++){
				cnt+=a[i]-a[j];
			}
			if(cnt<=m){
				return 1;
			}
			
		}
		return 0;
	}
	else{
		int cnt=0;
		for(int j=1;j<=h;j++){
			cnt+=a[h]-a[j];
		}
		if(cnt<=m){
			return 1;
		}
		else{
			return 0;
		}
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]-a[i-1]!=p&&i>=3)
			f=0;
		p=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(g(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
