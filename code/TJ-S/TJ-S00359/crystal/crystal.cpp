#include<bits/stdc++.h>
using namespace std;
int n,x;
long long m,a[500001],s[500001],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    	s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=0,R=i;
		while(L+1<R){
			int M=(L+R)/2;
			if(a[i]*(i-M+1)-(s[i]-s[M-1])<=m)
				R=M;
			else
				L=M;
		}
		x=max(x,i-R+1);
	}
	printf("%d\n",x);
	return 0;
}
