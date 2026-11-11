#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],num[N];

int find(int x,int t,int w,int y){
	int l=0,r=y,mid;
	int res=y;
	while(l<=r){
		int mid=(l+r)/2;
		if(t*(y-mid)+num[mid]-w<=x){
			r=mid-1,res=mid;
		}else{
			l=mid+1;
		}
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
		int p=find(m,a[i],num[i],i);
		ans=max(ans,i-p);
	}
	cout<<ans<<"\n";
	return 0;
}

