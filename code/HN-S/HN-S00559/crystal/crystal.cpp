#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],bestx=-1,l,ans;
bool qwq=1;
unsigned long long sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n-2;i++){
		if (a[i+1]-a[i]!=a[i+2]-a[i+1]){
			qwq=0;
			break;
		}
	}
	if (qwq==1){
		ans=1;
		long long p=a[2]-a[1];
		for (int i=1;i<=n;i++){
			m-=i*p;
			if (m<0){
				break;
			}
			ans++;
			if (m==0){
				break;
			}
		}
		printf("%lld",ans);
	}
	else{
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++){
			ans=1;
			sum=0;
			l=i-1;
			while (sum<m){
				if (l==0){
					break;
				}
				sum+=a[i]-a[l];
				if (m==sum){
					ans++;
					break;
				}
				else if (m<sum){
					break;
				}
				ans++;
				l--;
			}
			bestx=max(bestx,ans);
		}
		printf("%lld",bestx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
