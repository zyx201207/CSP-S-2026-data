#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const long long N=1e6+5,B=131;
ll n,m,k,t,sum=0,ans=0;
ll a[500005],pre[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
		if(pre[i]<=m){
			ans=max(ans,i+0ll);
		}else {
			int l=1,r=i;
			while(l<=r){
				//cout<<i<<" "<<l<<" "<<r<<"\n";
				int p=(l+r)/2;
				if(pre[i]-pre[p]-(p-1)*(a[i]-a[p])<=m){
					ans=max(ans,i-p+1ll);
					r=p-1;
				}else l=p+1;
			}
				
		}
		
	}
	
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

3
-
5 8
-3 -1 2 2 7

4 

-
5 1
1 1 5 5 4

3

	 /\_/\   ?
	( o o ) 
   \/    \

*/