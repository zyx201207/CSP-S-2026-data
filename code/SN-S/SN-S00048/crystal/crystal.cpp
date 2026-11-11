#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
struct node{
	long long cnt,sum;
}b[500005];
long long a[500005];
long long n,m,maxx=-1e18-5,ans,minx=1e18+5;
int fin(int m){
	int r=0,l=n;
	int mid;
	while(r<l){
		mid=(r+l+1)/2;
		if(a[mid]<=m) r=mid;
		else l=mid-1;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		maxx=max(a[i],maxx);
		minx=min(minx,a[i]);
	}	
	sort(a,a+n);
	b[0].sum=a[0];
	b[0].cnt=1;
	for(int i=1;i<n;i++){
		b[i].sum=b[i-1].sum+a[i];
		b[i].cnt=i+1;
	}
	int l=minx,r=maxx;
	long long sum2=0,sum1=-1e9;
	while(l<r){
		sum2=0;
		int mid=(l+r)/2;
		long long x=fin(mid);
		long long j,cnt=0;
		for(j=x;j>=0;--j){
			sum2+=a[x]-a[j];
			if(sum2>m){
				sum2-=a[j];
				break;
			}
			cnt++;
		}
		for(int j=x+1;;j++){
			if(a[j]==a[x]) cnt++;
			else break;
		}
		ans=max(ans,cnt);
		if(sum2>=m) r=mid;
		else l=mid+1;
		
	}
	printf("%lld",ans);
	return 0;
}
