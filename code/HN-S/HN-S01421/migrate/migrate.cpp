#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int pre[2000005],nex[2000005],pd[2000005];
int R[2000005],c[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--){
		long long n;
		long long d;
		scanf("%lld%lld",&n,&d);
		x[5]=-2000000000000000000;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(C>=11&&C<=12){
			if(x[2]-x[1]==0){
				printf("0\n");
				continue;
			}
			if((long long)(d/(x[2]-x[1]))>1&&n>=(long long)(d/(x[2]-x[1]))*2)printf("%lld\n",n-(long long)(d/(x[2]-x[1]))*2+1);
			else printf("0\n");
			// cout<<n-3<<" ";
			// if(n>=4&&x[1]+d<x[4]&&x[1]+2*d>=x[4])cout<<n-3<<"\n";
			// else cout<<0<<"\n";
		}
		else if(C>=13&&C<=14){
			int r=1;
			long long dw=0;
			for(int i=1;i<=n;i++)pd[i]=0;
			for(int i=1;i<n;i++){
				while(r<n&&x[r+1]-x[r]+dw<=d){
					dw=dw+x[r+1]-x[r];
					r++;
				}
				// nex[i]=r;
				if(r-i>1)
					pd[r]++;
				dw-=x[i+1]-x[i];
			}
			int l=n;dw=0;
			int ans=0;
			for(int i=n;i>1;i--){
				while(l>1&&x[l]-x[l-1]+dw<=d){
					dw=dw+x[l]-x[l-1];
					l--;
				}
				// pre[i]=l;
				if(i-l>1)
					ans+=pd[l+1];
				dw-=x[i]-x[i-1];
			}
			cout<<ans<<"\n";
		}
		else{
			int r=1;
			long long dw=0;
			for(int i=1;i<=n;i++)pd[i]=0;
			for(int i=1;i<n;i++){
				dw=max(0ll,dw);
				r=max(r,i);
				while(r<n&&x[r+1]-x[r]+dw<=d){
					dw=dw+x[r+1]-x[r];
					r++;
				}
				// cout<<i<<" "<<r<<"\n";
				nex[i]=r;
				dw-=x[i+1]-x[i];
			}
			int l=n;dw=0;
			long long ans=0;
			for(int i=n;i>1;i--){
				dw=max(0ll,dw);
				l=min(l,i);
				while(l>1&&x[l]-x[l-1]+dw<=d){
					dw=dw+x[l]-x[l-1];
					l--;
				}
				pre[i]=l;
				dw-=x[i]-x[i-1];
			}
			for(int i=1;i<n;i++){
				for(int j=i+3;j<=n;j++){
					int ee=1;
					int X=i;
					int tot=0;
					while(nex[X]<j){
						if(X==nex[X]){
							ee=1;
							break;
						}
						X=nex[X],ee++,R[++tot]=X;
					}
					if(ee<=1)continue;
					X=j;
					int yu=tot;
					while(pre[X]>i){
						X=pre[X],c[tot--]=X;
					}
					int er=0;
					for(int u=1;u<=yu;u++){
						er+=abs(R[u]-c[u]);
					}
					if(er==1)ans++;
				}
			}
			printf("%lld\n",ans);
		}

	}
	return 0;
}