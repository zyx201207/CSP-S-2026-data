#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],mx;
bool check(long long mid,int i){
	if((i-mid)*a[i]-(pre[i-1]-pre[mid-1])>m)return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,ans=1e18;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		mx=max(i-ans+1,mx);
	}
	cout<<mx;
	return 0;
} 