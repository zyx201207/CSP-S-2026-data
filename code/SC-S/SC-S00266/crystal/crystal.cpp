#include<bits/stdc++.h>
using namespace std;
long long c[500007];
long long a[500007];
long long qzh[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		c[i]=a[i+1]-a[i];
		qzh[i]=qzh[i-1]+c[i];
	}
	int l=1,r=1,maxn=1,len=1;
	long long sum=0;
	while(r<n){
		r++;
		sum+=len*c[r-1];
		len++;
		if(sum<=m){
			maxn=max(maxn,len);
			continue;
		}
		else{
			while(l<r){
				sum-=1ll*qzh[r-1]-1ll*qzh[l-1];
				l++;
				len--;
				if(sum<=m){
					maxn=max(maxn,len);
					break;
				}
			}
			
		}
	}
	cout<<maxn;
	return 0;
}