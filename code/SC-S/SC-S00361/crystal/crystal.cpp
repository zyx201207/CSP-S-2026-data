#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,maxn=0,sum,tag=0,tag1;
	long long m,a[50010],b[50010],c[50010],delta,k;
	memset(c,0,sizeof(c));
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	b[1]=1;
	for(int i=1;i<=n;i++){
		if(i!=n){
			if(a[i]!=a[i+1]){
				b[i+1]=1;
				c[i]=a[i+1]-a[i];
			}
			else{
				b[i]++;
				b[i+1]=b[i];
			}
		}
		else{
			c[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		sum=0;
		if(c[i]){
			if(tag==1&&m/c[tag1]<=b[tag1]){
				sum=b[i]+m/c[tag1];
				if(sum>maxn) maxn=sum;
			}
/*			if(m/c[tag1]>b[tag1]&&tag==1){
				delta=m;
				k=tag1;
				sum=b[i];
				while(delta/c[k]>b[k]&&k>0){
					sum+=b[k];
					delta=delta-b[k]*c[k];
					k=k-b[k];
				}
				if(sum>maxn) maxn=sum;
			}*/
			tag=1;
			tag1=i;
		}
	}
	printf("%d",maxn);
	return 0;
} 