#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1;
	long long sum=0;
	for(int i=1;i<=n;i++){
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
		sum+=1ll*(a[i+1]-a[i])*(i-l+1);
	}
	printf("%d",ans);
	return 0;
}