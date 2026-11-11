#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,sum,cnt,ans,id=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]*cnt-sum<=m){
			cnt++;
			ans=max(ans,cnt); 
		} 
		else{
			while(a[i]*cnt-sum>m){
				cnt--;
				sum-=a[id];
				id++;
			}
			cnt++;
		}
		sum+=a[i];
	}
	printf("%lld",ans);
	return 0;
} 
