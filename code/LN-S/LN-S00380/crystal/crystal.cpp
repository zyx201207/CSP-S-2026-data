#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500020],b[500020],p,c[500020],ans,kg1,kg2,d;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=a[i-1]+1) kg1=1;
        if(a[i]!=a[i-1]) b[++p]=a[i];
        else c[p]++;
    }
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]) kg2=1;
        d=a[i]-a[i-1];
    }
    if(!kg1){
        ans=0;
        for(int i=1;i<n;i++){
            ans+=i;
            if(ans>m){
                printf("%lld",i);
                return 0;
            }
        }
        printf("%lld",n);
        return 0;
    }
    if(!kg2){
        d=abs(d),ans=0;
        for(int i=1;i<n;i++){
            ans+=i*d;
            if(ans>m){
                 printf("%lld",i);
                 return 0;
            }
        }
        printf("%lld",n);
        return 0;
    }
    for(int i=1;i<=p;i++) c[i]++;
    for(int i=1;i<=p;i++){
        int sum=0,cnt=c[i],x=b[i-1],y=b[i],z=b[i+1];
        if((i==1||b[i-1]<b[i])&&(i==p||b[i]<b[i+1])){
            for(int j=i-1;j>=1;j--){
                if(b[j+1]>b[j]){
                    sum+=c[j]*(b[i]-b[j]);
                    if(sum>m) break;
                    cnt++;
                }
                else break;
            }
        }
        else if((i==1||b[i-1]>b[i])&&(i==p||b[i]>b[i+1])){
            for(int j=i+1;j<=n;j++){
                if(b[j-1]>b[j]){
                    sum+=c[j]*(b[i]-b[j]);
                    if(sum>m) break;
                    cnt++;
                }
                else break;
            }
        }
        else if(b[i]>b[i-1]&&b[i]>b[i+1]){
            int l=i-1,r=i+1,kgl=0,kgr=0;
            while(sum<=m){
                if(b[l]>b[l+1]) kgl=1;
                if(b[r]<b[r-1]) kgr=1;
                if(b[i]-b[l]>b[i]-b[r]&&!kgr) sum+=c[r]*(b[i]-b[r]),cnt++,r++;
                else if(!kgl) sum+=c[l]*(b[i]-b[l]),cnt++,l--;
                if(kgl&&kgr) break;
            }
        }
        else{
            int l=i-1,r=i+1,kgl=0,kgr=0;
            while(sum<=m){
                if(b[l]<b[l+1]) kgl=1;
                if(b[r]>b[r-1]) kgr=1;
                if(b[l]>b[r]&&!kgr) sum+=cnt*c[r]*(b[r]-b[r-1]),cnt++,r++;
                else if(!kgl) sum+=cnt*c[l]*(b[l]-b[l+1]),cnt++,l--;
                if(kgl&&kgr) break;
            }
        }
        ans=max(ans,cnt);
    }
    printf("%lld",ans);
}
