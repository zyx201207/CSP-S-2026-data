#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N],cnt=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
//		cout<<i<<"!!!\n";
		if(a[i]*(i-1)-pre[i-1]<=m){
			cnt=i;
		}
		else{
			int l=0,r=i+1,L=i;
			while(l<=r){
				int mid=l+(r-l)/2;
				if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m){
					r=mid-1;
					L=mid;
				}
				else{
					l=mid+1;
				}
//				cout<<l<<" "<<r<<" "<<mid<<"\n"; 
			}
			if(L>=1&&L<=i) cnt=max(cnt,i-L+1);
		}
	}
	printf("%lld",cnt);
	return 0;
}
/*
14:50 got it!
*/
