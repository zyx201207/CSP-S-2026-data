#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			a[r]=0;
		}else{
			a[r]-=a[l];
			a[l]=0;
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
