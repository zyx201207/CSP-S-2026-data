#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N];
bool check(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	if(sum>m)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=n,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			res=mid;
		}
		else r=mid-1;
	}
	cout<<res<<endl;
}