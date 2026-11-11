#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,ans;
int a[N],b[N];
void f(){
	int sum=0,l=1;
	for(int r=1;r<=n;r++){
		sum=sum+(a[r]-a[r-1])*(r-l);
		if(sum>m){
			while(sum>m&&l<=r){
				sum-=(a[r]-a[l]);
				l++;
			}
		}
		ans=max(ans,r-l+1);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f();
	cout<<ans;
	return 0;
}