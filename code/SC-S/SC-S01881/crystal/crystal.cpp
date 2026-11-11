#include<bits/stdc++.h>
using namespace std;
long long a[50000005];
long long n,m,sum=0,pj,p=0,pq,ph,ans=1,minn=100000;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	pj=ceil(sum*1.0/n);
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		a[i]=a[i]-pj;
		if(abs(a[i]-0)<minn){
			p=i;
			minn=abs(a[i]-0);
		}
	}
	pq=p-1;
	for(long long i=p+1;i<=n;i++){
		if(a[i]==a[p]) ans++;
		else{
			ph=i;
			break;
		}
	}
	long long phz=0;
	while((m>=a[p]-a[pq]&&pq>=0)||(m>=phz&&ph<n)){
		phz=(p-pq+1)*(a[ph]-a[p]);
		if(a[p]-a[pq]<=phz&&m>=a[p]-a[pq]&&pq>=0){
			m-=a[p]-a[pq];
			a[pq]=a[p];
			pq-=1;
			ans++;
		}
		else if(a[p]-a[pq]>phz&&m>=phz&&ph<n){
				for(long long i=pq+1;i<=ph;i++)
					a[i]=a[ph];
				m-=phz;
				ph+=1;
				ans++;
			}
		
	}
	printf("%lld\n",ans);
	return 0;
} 