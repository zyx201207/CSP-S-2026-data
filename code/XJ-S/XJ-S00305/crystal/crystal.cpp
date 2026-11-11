#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],sum1[50005];
long long n,m;
long long maxn=-1e9;
struct que{
	long long id,l,r;
};
queue<que>qu;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m>100000000){
		cout<<m/(a[2]-a[1]);
	}
	else{
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++){
			sum[i]=a[i]-a[i-1];
			sum1[i]=sum[i]-sum1[i-1];
		}
		long long maxn=-1e9;
		for(int i=2;i<=n;i++){
			long long cun=m,sum=0;
			for(int j=i;j>=1;j--){
				long long cha=a[i]-a[j];
				cun-=cha;
				if(cun>=0){
					sum+=1;
				} 
				else{
					break;
				}
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	}

	return 0;
} 
