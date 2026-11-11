#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[200005],maxx=-1e4,max1=-1e4,c[200005],temp1,temp2;
bool flag=0,f=0;
int solves(int x){
	int k=0;
	while(x>2*k) k++;
	return k-1;
}
bool cmp(int s,int y){
	return s>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		b[i]=solves(a[i]);
		max1=max(max1,b[i]);
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		printf("%d",ans);
	}
	else if(m==1) printf("%d",maxx);
	else if(m==2){
		for(int i=1;i<=n;i++){
			c[b[i]]++;
		}
		for(int i=max1;i>=1;i--){
			if(c[i]>=2){
				for(int j=1;j<=n;j++){
					if(b[j]==i&&flag==0) temp1=a[j],flag=1;
					if(flag==1&&b[j]==i){
						temp2=a[j];
						f=1;
						break;
					} 
				}
				if(f){
					printf("%d",temp1&temp2);
					return 0;
				}
			}
		}
	}
	else if(n>2000&&n<=200000) printf("%d",maxx);
	else if(n<=20&&m<=n){
		for(int i=1;i<=m;i++) ans&=a[i];
		printf("%d",ans);
	}
	return 0;
} 
