#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005];
int n,m;
bool check(int r,int x2){
	int l=r-x2+1;
	__int128 num=(r-l+1)*a[r];
	num-=(b[r]-b[l-1]);
	int k=(long long)(num);
	return num<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-1);	
	}
	cout<<ans;
} 
