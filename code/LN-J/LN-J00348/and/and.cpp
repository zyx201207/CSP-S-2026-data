#include<bits/stdc++.h>
using namespace std;
long long n,m,vis[60],bi=0;
struct numm{
    long long nu;
    string doub="";
}a[300000];
bool cmp(numm x,numm y){
    long long xx=0,yy=0;
    for(int i=0;i<=bi-1;i++){
        xx+=x.doub[i]-'0';
        yy+=y.doub[i]-'0';
        xx*=2,yy*=2;
    }
    return xx>yy;
}
long long ans=0;
int main(){
    freopen("and5.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,0,sizeof(vis));
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].nu);
        long long y=a[i].nu,b=0;
        while(y) a[i].doub+=char(y%2+'0'),vis[++b]+=y%2,y/=2;
        for(int j=1;j<=50;j++) a[i].doub+='0';
        bi=max(bi,b);
    }
    sort(a+1,a+n+1,cmp);
    for(;bi>=1;bi--){
        for(;bi>=1;bi--) if(vis[bi]>=m) break;
        if(bi<1) break;
        //int sss=1;
        //for(;sss<=n;sss++) if(a[sss].doub[bi-1]=='1') break;
        //for(int i=1;i<=n-sss+1;i++) swap(a[i],a[i+sss])a[i]=a[i+sss-1];
        sort(a+1,a+n+1,cmp);
        int l=0,r=n+1;
        while(l+1<r){
            int m=(l+r)/2;
            if(a[m].doub[bi-1]=='1') l=m;
            else r=m;
        }
        for(int i=r;i<=n;i++){
            int j=a[i].nu,b=0;
            while(j) vis[++b]-=j%2,j/=2;
        }
        n=r-1;
        long long ll=1;
        for(int k=1;k<bi;k++) ll*=2;
        ans+=ll;
        for(;bi>=1;bi--) if(vis[bi]>=m) break;
        if(bi<1) break;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
