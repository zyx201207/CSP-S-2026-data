#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long 
using namespace std;
const int INF=2e18,N=5e5+10;
int n,m,a[N],s[N],ans,mx=0;
bool check(int x,int y){
	int u=(y-x+1)*a[y]-(s[y]-s[x-1]);
	return u<=m;
}
signed main(){
	IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i,mid)){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		mx=max(mx,ans-i+1);
	}
	cout<<mx;
	return 0;
} 
