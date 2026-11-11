#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],l[35]={1},sum,t;
int add(int x,int y){
	int b[35],c[35],ans[35],lenb=0,lenc=0;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(ans,0,sizeof(ans));
	while(x){
		b[lenb++]=x%2;
		x/=2;
	}
	while(y){
		c[lenc++]=y%2;
		y/=2;
	}
	int minlen=min(lenb,lenc);
	for(int i=0;i<minlen;i++){
		if(b[i]==1 && c[i]==1) ans[i]=1;
	}
	int sum=0;
	for(int i=0;i<minlen;i++) sum+=ans[i]*l[i];
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=30;i++) l[i]=l[i-1]*2;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=30;j++){
			if(a[i]==(l[j]-1)){
				sum++;
				break;
			}
		}
	}
	if(sum==n){
		sort(a+1,a+1+n);
		printf("%d\n",a[n-m+1]);
		return 0;
	}//A
	if(m==1){
		sort(a+1,a+1+n);
		printf("%d\n",a[n]);
		return 0;
	}
	if(m==2){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=m;j++){
				cnt=add(a[i],a[j]);
				if(cnt>ans) ans=cnt;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==3){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					cnt=add(a[i],a[j]);
					cnt=add(cnt,a[k]);
					if(cnt>ans) ans=cnt;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==4){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						cnt=add(a[i],a[j]);
						cnt=add(cnt,a[k]);
						cnt=add(cnt,a[b]);
						if(cnt>ans) ans=cnt;
					}
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==5){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							cnt=add(a[i],a[j]);
							cnt=add(cnt,a[k]);
							cnt=add(cnt,a[b]);
							cnt=add(cnt,a[c]);
							if(cnt>ans) ans=cnt;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==6){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								cnt=add(a[i],a[j]);
								cnt=add(cnt,a[k]);
								cnt=add(cnt,a[b]);
								cnt=add(cnt,a[c]);
								cnt=add(cnt,a[d]);
								if(cnt>ans) ans=cnt;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==7){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								for(int e=d+1;e<=n;e++){
									cnt=add(a[i],a[j]);
									cnt=add(cnt,a[k]);
									cnt=add(cnt,a[b]);
									cnt=add(cnt,a[c]);
									cnt=add(cnt,a[d]);
									cnt=add(cnt,a[e]);
									if(cnt>ans) ans=cnt;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	t=a[n];
	for(int i=n-1;i>=n-m+1;i--) t=add(t,a[i]);
	printf("%d\n",t);
	return 0;
}
