#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9; 
int n,m,a[N],cz;
int sum,ans=1;
bool flag;
bool check(int r,int x){
	sum=0;
	for (int i=x+1;i<=r;i++){
		sum=max(1ll*(-1),sum+(i-x)*(a[i]-a[i-1]));
	}
	if (sum<0) return false;
	if (sum<=m){
		return true;
	}
	return false;
}
void work(int R){
	int l=1,r=R;
	while(l<=r){
		int mid=(l+r)>>1;
		if (check(R,mid)){
			ans=max(ans,R-mid+1);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if (n<=1e4) flag=false;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i==2) cz=a[i]-a[i-1];
		if (i>2&&(a[i]-a[i-1])!=cz){
			flag=false;
		}
	}
	sort(a+1,a+1+n);
	if (flag){
		for (int i=2;i<=n;i++){
			int x=max(1ll*(-1),((i-1)*(a[i]-a[i-1])));
			if (m<x){
				cout<<i-1<<"\n";
				return 0;
			}
			m=max(1ll*(-1),m-x);
	//		cout<<sum<<" ";		
		}
	}
	else{
		for (int i=n;i>=1;i--){
			work(i);
		}
		cout<<ans;		
		return 0;
	}
	return 0;
}