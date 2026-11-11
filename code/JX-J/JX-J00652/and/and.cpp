#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++){
        b[i]=a[i];
    }
    long long f=0,ans=b[1];
    for(int i=2;i<=m;i++){
        if(f){
            ans=ans&b[i-1];
            f==0;
        }
        if(ans&b[i]==0){
            f=1;
            ans=ans&b[i+1];
        }
        else{
            ans=ans&b[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
