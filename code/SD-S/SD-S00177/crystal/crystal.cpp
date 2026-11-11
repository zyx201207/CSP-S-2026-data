#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
int l,r;
bool check(int x){
	int p=a[x];
	int sum=0,minn=1e18+10;
	for(int i=1;i<=x;i++) sum+=p-a[i];
	minn=sum;
	for(int i=2;i+x-1<=n;i++){
		int j=i+x-1;
		sum-=a[j-1]-a[i-1];
		sum+=(a[j]-a[j-1])*(x-1);
		minn=min(minn,sum);
	}
	if(minn>m) return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;	
} 
