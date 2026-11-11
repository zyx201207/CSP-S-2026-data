#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int t=1,cnt=1;
	long long sum=m;
	for(int i=2;i<=n;i++){
		long long b=a[i]-a[i-1];
		if(b>m){
			ans=max(ans,cnt);
			cnt=1;
			t=i;
		}
		if(b*(i-t)<=sum){
			cnt++;
			ans=max(ans,cnt);
			sum-=b*(i-t);
		}
		else{
			ans=max(ans,cnt);
			while(b*(i-t)>sum){
				sum+=(a[i-1]-a[t]);
				t++;
				cnt--;
			}
			cnt++;
			sum-=b*(i-t);
		}
	}
	printf("%d\n",ans);
	return 0;
} 
