#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e5+5;
long long a[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int j=1;j<=n;j++){
		int l=1,r=j;
		while(l<r){
			int mid=(l+r)>>1;
			long long t=a[j]*(j-mid+1)-s[j]+s[mid-1];
			if(t>m){
				l=mid+1;
			}
			else{
				r=mid;
			}
		} 
		ans=max(ans,j-l+1);
	}
	printf("%d",ans);
	return 0; 
} 
