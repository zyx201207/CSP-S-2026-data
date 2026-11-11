#include<cstdio>
#include<iostream>
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	    scanf("%lld %c",&a[i],&c[i]);
	    long long ans=0;
	    int l=0,r=n-1;
	    long long x=a[l],y=a[r];
	    while(l<r){
	    	long long k=x<y?x:y;
	    	if(c[l]!=c[r])ans+=k;
	    	x-=k;y-=k;
	    	if(!x)x=a[++l];
	    	if(!y)y=a[--r];	
		}
		printf("%lld\n",ans);
		return 0;
} 
