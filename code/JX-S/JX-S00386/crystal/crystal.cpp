#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];//i: a[i]-a[i-1]
long long m;
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d",&n);
    scanf("%lld",&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    //A and B
    bool f=1;
    int b=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(b!=a[i]-a[i-1]){
            f=0;
        }
    }
    long long t=abs(b);
    long long ans=1;
    if(f){
        while(m>=0 && ans<n){
            m-=t;
            ++ans;
            t+=b;
        }
        printf("%lld",ans);
        return 0;
    }

    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    int cnt=1;
    long long maxans=0;
    for(int i=1;i<=n;i++){
        ans=0;
        while(m>=0 && ans<n){
            m-=d[cnt];
            ++ans;
            ++cnt;
        }
        maxans=max(maxans,ans);
    }
    printf("%lld",maxans);
    return 0;
}
