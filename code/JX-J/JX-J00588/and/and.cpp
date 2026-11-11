#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long x=-1;
long long dn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        x=max(x,a[i]);
        if(i!=1){
            dn=dn&a[i];
        }else{
            dn=a[i];
        }
    }
    if(m==1){
        printf("%lld",x);
        return 0;
    }
    if(m==n){
        printf("%lld",dn);
        return 0;
    }
    if(m==2){
        long long p=0,xx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p=a[i];
                p=p&a[j];
                cout<<i<<" "<<j<<" "<<p<<endl;
                xx=max(xx,p);
            }
        }
        cout<<xx;
    }
    return 0;
}
