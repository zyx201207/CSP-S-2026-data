#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n;
ll a[N],b[N],ans=1,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int left=1,right=i;
		while(left<=right){
			int mid=left+right>>1;
			if(a[i]*ll(i-mid+1)-(b[i]-b[mid-1])<=m){
				ans=max(ans,ll(i-mid+1));
				right=mid-1;
			}else left=mid+1;
		}
	}
	printf("%lld",ans);
	return 0;
}

