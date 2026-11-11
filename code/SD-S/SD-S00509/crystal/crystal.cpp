#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,a[N],avg,b[N];
int n;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) b[i]=n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n>=31622){//特殊性质 30pts
		long long ans=0;
		for(int i=1;i<n;i++){
			if((a[i]-a[1]+a[i]-a[i-1])*i/2<=m&&(a[i+1]-a[1]+a[i+1]-a[i])*(i+1)/2>=m){
				avg=i+1;
				break;
			}
		}for(int i=avg;i>=1;i--){
			if(a[i]<=a[avg]&&m-a[avg]+a[i]>=0){
				ans++;
				m-=a[avg]-a[i];
			}if(m<=0){
				break;
			}
		}
		for(int i=avg+1;i<=n;i++){
			if(a[i]==a[avg]){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		
	}else{//暴力 45pts 
		long long ans=0;
		for(int i=2;i<=n;i++){
			int t=m;
		    for(int j=n;j>=2;j--){
	    		t-=a[j]-a[j-1];
	    		b[i]--;
	    		if(t<0){
	    			b[i]++;
	    			break;
				}
			}
			b[i]=min(b[i],b[i-1]);
		}
		avg=b[n];
		avg=n-avg+1;
		for(int i=avg;i>=1;i--){
			if(a[i]<=a[avg]&&m-a[avg]+a[i]>=0){
				ans++;
				m-=a[avg]-a[i];
			}if(m<=0){
				break;
			}
		}
		for(int i=avg+1;i<=n;i++){
			if(a[i]==a[avg]){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
//还不错，期望值75pts 二等奖稳啦
//这可能是我此生最后一次打CSP了，学文化课学傻了，初四和高中退役吧，希望大学还有缘相见 
