#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1,sum[N],c,pos=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	//bool f=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	/*long long cj=a[2]-a[1];
	for (int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cj){
			f=true;
			break;
		}
	}*/
	sort(a+1,a+n+1);
	/*if(!f){
		long long num=0;
		for (int i=1;i<=n;i++){
		    num+=cj*(i-1);
			if(num>m){
				ans=i-1;
				break;
			}	
		}
		if(num<=m){
			ans=n;
		}
		printf("%lld",ans);
		return 0;
	}*/
	for (int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for (int i=2;i<=n;i++){
		//long long num=0;
		/*for (int j=i;j>0;j--){
			num+=(a[i]-a[j]);
			if(num>m){
				long long k=i-j;
				ans=max(ans,k);
				break;
			}
		}
		if(num<=m){
			ans=i;
		}*/
		//cout << sum[i] << endl;
		c+=(pos-1)*(a[i]-a[i-1]);
		while(sum[i]-c>m){
			c+=(a[i]-a[pos]);
			pos++;
		}
		ans=max(ans,i-pos+1); 
	}
	printf("%lld",ans);
	return 0;
}
