#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
int ans;
long long sum[N];//前缀和优化
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int answer=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int use=(i-mid+1)*a[i];
			if(use-(sum[i]-sum[mid-1])>m){
				l=mid+1;
			}else{
				answer=max(answer,i-mid+1);
				r=mid-1;
			}
		}
		ans=max(answer,ans);
	}
	cout<<ans;
	return 0;
} 
 