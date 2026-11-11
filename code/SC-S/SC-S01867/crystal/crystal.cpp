#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
int d[500005];
int n,m;
int check(int j,int i){
	int x=d[i]*(i-j);
	int y=b[j]-b[i]-x;
	return y<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[n]-a[i];
	}
	for(int i=n;i>=1;i--){
		b[i]=b[i+1]+d[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int an=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				an=i-mid+1;
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}
/*5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/