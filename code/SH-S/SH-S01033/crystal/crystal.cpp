#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;

int n,m;
int a[N];
int sum[N];

bool check(int mid,int now){
	if(a[mid]*(mid-now)-(sum[mid-1]-sum[now-1])<=m) return 1;
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	/*for(int i=1;i<=n;i++){
		cout<<cha[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<" ";
	}*/
	//cout<<1;
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		//	cout<<l<<" "<<r<<" "<<mid<<endl;
		}
		ans=max(ans,l-i);
	}
	cout<<ans;
}
