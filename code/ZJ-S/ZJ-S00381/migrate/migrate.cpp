#include<bits/stdc++.h>
using namespace std;
int C,T,n,sum[2000005],f[2000005],k,l,pre,p,g;
long long d,a[2000005],ans;
bool ff;
void work(int x,int y,int now){
//	printf("A %d %d %d %d\n",x,y,now,k);
	if(x>=y){
		if(now==l) k++;
		if(k>2) ff=0;
		return;
	}
	if(now>=l) return;
	for(int i=x+1;i<=min(f[x],y);i++){
		work(i,y,now+1);
		if(ff==0) return;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1];
			if(i==1&&a[2]-a[1]>d) sum[i]++;
			else if(i==n&&a[n]-a[n-1]>d) sum[i]++;
			else if(a[i]-a[i-1]>d&&a[i+1]-a[i-1]>d) sum[i]++;
		}
//		printf("sum\n");
//		for(int i=1;i<=n;i++) printf("%d ",sum[i]);
//		printf("\n");
		for(int i=1;i<=n;i++){
			int j=0;
			if(i==1) j=i+1;
			else j=f[i-1];
			while(a[j]-a[i]<=d&&j<=n) j++;
			f[i]=j-1;
		}
//		printf("f\n");
//		for(int i=1;i<=n;i++) printf("%d ",f[i]);
//		printf("\n");
		ans=0;
		for(int i=1;i<n;i++){
			pre=i;
			l=2;
			for(int j=i+1;j<=n;j++){
				if(sum[j-1]-sum[i]||a[i+1]-a[i]>d||a[j]-a[j-1]>d) continue;
				p=pre;
				l=max(1,l-1);
				g=0;
				while(f[p]<j){
					pre=p;
					if(f[p]-p==1) g++;
					p=f[p];
					l++;
				}
				if(f[p]-p==1) g++;
//				printf("%d %d %d\n",i,j,l);
				if(j-i==l*d||g==l) continue;
				k=0;
				ff=1;
				work(i,j,0);
				if(ff==1&&k==2) ans++;
//				printf("%d %lld\n",k,ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}