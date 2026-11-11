#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=0;
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		if(cnt>ans){
			ans=cnt;
		}
	}
	printf("%lld",ans);
	return 0;
}