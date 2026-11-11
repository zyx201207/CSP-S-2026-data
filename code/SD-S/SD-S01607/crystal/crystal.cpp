#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[500001];
int c[500001];
int find(int l,int r,int pos){
	while(l<=r){
		int mid=(l+r)>>1;
		int x=(pos-mid)*a[pos]-(c[pos-1]-c[mid-1]);
		if(x==m){
			return mid;
		}else if(x>m){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l; 
}
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	int ans=1ll;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m) continue;
		int t=find(1,i-1,i);
		int u=(i-t)*a[i]-(c[i-1]-c[t-1]);
		if(u>m){
			while(u>m){
				t++;
				u=(i-t)*a[i]-(c[i-1]-c[t-1]);
			}
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans<<endl;
	return 0;
}
