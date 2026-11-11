#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long s;
long long a[500001],b[500001];
int main(){
    s=0;
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d",&n);
    scanf("%ld",&m);
    for(int i=1;i<=n;i++){
        scanf("%ld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int ans=1,zs=0;
    for(int i=n,j=n;j>=2;j--){
        zs+=b[j];
        s+=zs;
        if(s>m){
            while(s>m){
                s-=(i-j+1)*b[i];
                zs-=b[i];
                i--;
            }
        }
        ans=max(ans,i-j+2);
    }

    printf("%d",ans);
    return 0;
}
