#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=5e5+2;
int n,m,a[mxn],k;
bool fl2=1;
inline bool check(int x){
	if(fl2){
		return (k*x*x+k*x<=2*m);
	}
	int sum=0ll;
	bool fl=0;
	for(int i=x;i<=n;i++){
		sum=fl=0ll;
		for(int j=i-x+1;j<i;j++){
			if(sum+a[i]>m+a[j]){
				fl=1;
				break;
			}else{
				sum+=a[i]-a[j];
			}
		}
		if(!fl&&sum<=m) return 1;
	}
	return 0;
}
int ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]+a[i-2]!=a[i-1]*2) fl2=0;
	}
	
	k=a[2]-a[1];
	sort(a+1,a+1+n);
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<(ans<=1?0:ans);
}