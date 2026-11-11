#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[200001],ma=0,s=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ma<(a[i] & a[j]))ma=(a[i] & a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(ma<(a[i] & a[j] & a[k]))ma=(a[i] & a[j] & a[k]);
                }
            }
        }
        cout<<ma;
        return 0;
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        if(ma<(a[i] & a[j] & a[k] &a[x]))ma=(a[i] & a[j] & a[k] & a[x]);
                    }
                }
            }
        }
        cout<<ma;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    s=a[1];
    for(int i=2;i<=m;i++){
        s=(s & a[i]);
    }
    cout<<s;
    return 0;
}
