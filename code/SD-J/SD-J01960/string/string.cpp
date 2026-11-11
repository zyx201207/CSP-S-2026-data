#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],cnt,x;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		x=min(a[l],a[r]);
		if(c[l]!=c[r]){
			cnt=cnt+x;
		}
		if(a[l]>a[r]){
			a[l]=a[l]-x;
			a[r]=0;
			r--;
		}
		else if(a[l]==a[r]){
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
		else{
			a[r]=a[r]-x;
			a[l]=0;
			l++;
		}
	}
	cout<<cnt;
	return 0;
}

