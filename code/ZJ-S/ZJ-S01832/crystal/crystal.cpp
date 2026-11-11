#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],c[N];
bool check(int l,int r,int x,int ba){
	int len=r-l+1;
	if(c[r]-c[l-1]-len*x>ba)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[n]-a[i];
	}
	int maxx=1;
    for(int i=n;i>=1;i--){
    	int l=1,r=i,mid,ans=1;
    	while(l<=r){
    		mid=(l+r)/2;
    		if(check(mid,i,a[n]-a[i],m)){
    			r=mid-1;
    			ans=i-mid+1;
			}
			else l=mid+1;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
}
