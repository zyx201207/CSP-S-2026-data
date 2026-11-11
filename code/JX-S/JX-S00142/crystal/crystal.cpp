#include<bits/stdc++.h>
using namespace std;
int a,d,e,f,g,ans,cnt,wh,x;
long long b,c,s[500010];
bool bo=1,boo=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%lld",&s[i]);
        if(i==1)x=s[i]-s[i-1];
        if(s[i]!=s[i-1]+x&&i>1)bo=0;
    }
    if(bo){
        int q=sqrt(b*2/x);
        printf("%d",q);
        return 0;
    }
    sort(s+0,s+a);
    for(int mid=-100010;mid<=100010;mid++){
        while(s[wh]<=mid&&wh<=a)wh++;
        //printf("%d\n",wh);
        c=b,cnt=0;
        for(int i=wh-1;i>=0&&c-(mid-s[i])>=0;i--){
            c=c-(mid-s[i]),cnt++;
        }
        ans=max(cnt,ans);
        //printf("%d %d\n",mid,ans);
    }
    printf("%d",ans);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int a,d,e,f,g,ans,cnt,wh;
long long b,c,s[500010];
bool bo;
signed main(){
    freopen("crystal4.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%d %lld",&a,&b);
    //printf("%d %lld\n",a,b);
    for(int i=0;i<a;i++){
        scanf("%lld",&s[i]);
        //printf("%lld ",s[i]);
    }
    sort(s+0,s+a);
    long long l=-1e4,r=1e4,mid=(l+r)/2;
    while(l<r-1){
        wh=a;
        for(int i=0;i<a;i++){
            if(s[i]>mid){
               wh=i;
               break;//I C
            }
        }
        c=b,cnt=0;
        //printf("%d %d\n",wh,mid);
        for(int i=wh-1;i>=0&&c>0;i--){
            //printf("%d %d  ||  ",c,mid-s[i]);
            c=c-(mid-s[i]),cnt++;
        }
        //printf("\n");
        ans=max(cnt,ans);
        printf("%lld %lld %lld %lld\n",l,r,mid,ans);
        if(c<=0)r=mid;
        else if(c>0)l=mid;
        mid=(l+r)/2;
    }
    printf("%d",ans);
    return 0;
}
*/
