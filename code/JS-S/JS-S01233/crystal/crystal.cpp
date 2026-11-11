#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l dr(){
    l x=0,f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
l a[500005],c[500005],s[500005],f=1,f2=1;
l p[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    l n,m;
    n=dr();
    m=dr();
    for(l i=1;i<=n;i++){
        a[i]=dr();
        if(a[i]!=i)f=0;
    }
    if(f){
        for(l i=1;i<=500005;i++){
            p[i]=i*(i-1)/2;
        }
        l t=upper_bound(p+1,p+500005+1,m)-p;
        cout<<t-1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(l i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    for(l i=2;i<=n-1;i++){
        if(c[i+1]!=c[i])f2=0;
    }
    if(f2){
        for(l i=1;i<=500005;i++){
            p[i]=c[2]*i*(i-1)/2;
        }
        l t=upper_bound(p+1,p+500005+1,m)-p;
        cout<<t-1;
        return 0;
    }
    s[1]=c[1];
    for(l i=2;i<=n;i++){
        s[i]=s[i-1]+c[i];
    }
    sort(s+1,s+n+1);
    l ans=0;
    for(l i=1;i<=n;i++){
        for(l j=i+1;j<=n;j++){
            l t=0;
            for(l k=i;k<j;k++){
                t+=s[j]-s[k];
            }
            if(t<=m){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
