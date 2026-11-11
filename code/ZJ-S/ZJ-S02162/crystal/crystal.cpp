#include <bits/stdc++.h>
#define MAXN 500005
typedef long long LL;
typedef unsigned long long uLL;
using namespace std;
int n,ans;
LL a[MAXN],b[MAXN];
uLL m;
int pjs(){
	LL sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	return int(sum*1.0/n+0.5);
}
int _find(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=x&&a[mid-1]<=x){
			int t1=a[mid]-x,t2=x-a[mid-1];
			if(t1<t2) return mid;
			return mid-1;
		}
		else if(a[mid-1]>x)r=mid;
		else
			l=mid;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	int t=pjs();
	//printf("%d\n",t);
	int ti=_find(t);
	//printf("%d\n",ti);
	t=a[ti];
	//printf("%d\n",t);
	
	for(int i=ti;i<=n;i++){
		if(a[i]==a[ti])ti=i;
		else
			break;
	}
	//printf("%d\n",ti);
	
	for(int i=1;i<=ti;i++)
		b[i]=t-a[i]/*,printf("%d %d %d\n",b[i],t,a[i])*/;
	
	sort(b+1,b+1+ti);
	LL sum=0;
	uLL sum2=0;
	for(int i=1;i<=ti;i++){
		//printf("%d %d \n",b[i],sum);
		sum+=b[i];
		if(sum2>m)break;
		ans++;
		if(sum>0){
			sum2+=sum;
			sum=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}