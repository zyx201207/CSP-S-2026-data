#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("crystal2.in","r",stdin);
   freopen("crystal.out","w",stdout);
    long long m;long long n;
    long long a[500005];
    scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
	long long x,xx;long long qz[500004];
	x=a[2]-a[1];
    qz[2]=x;qz[1]=0;qz[0]=0;
    for(int i = 3;i<=n;++i){
		if(a[i]==a[i-1]){qz[i]+=qz[i-1];x=qz[i];continue;}
        xx=x+a[i]-a[i-1];
        qz[i]=qz[i-1]+xx;
        x=xx;
    }
    int ans=0;
    int j=0;
    for(int i = 1;i<=n;i++){
		j=n;
        while(qz[j]-qz[j-1]-qz[i]+qz[i-1]>m)j--;
        if(j<=i)continue;
        ans=max(j-i+1,ans);
    }
	printf("%d",ans);
    return 0;
}

