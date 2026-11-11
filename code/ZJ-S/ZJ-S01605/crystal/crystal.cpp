#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],b[N];
int n,m;
int check(int l,int r){
	int k=b[r]-b[l-1];
	int num=r-l+1;
	if(a[r+1]*num-k<=m){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i-1)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}