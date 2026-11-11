#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],h,f,mi[2000005],mi2[2000005],sum[200005],sum2[200005],ans;
void cg(int x,int y){
    if(mi[x]+1<mi[y]){
        mi2[y]=mi[y];
        sum2[y]=sum[y];
        mi[y]=mi[x]+1;
        sum[y]=sum[x];
        if(mi2[x]+1<mi2[y]){
            mi2[y]=mi2[x];
            sum2[y]=sum2[y];
        }else if(mi2[x]+1==mi2[y]){
            sum2[y]+=sum2[x];
        }
    }else if(mi[x]+1==mi[y]){
        sum[y]+=sum[x];
        if(mi2[x]+1<mi2[y]){
            mi2[y]=mi2[x];
            sum2[y]=sum2[y];
        }else if(mi2[x]+1==mi2[y]){
            sum2[y]+=sum2[x];
        }
    }else{
        if(mi2[x]+1<mi2[y]){
            mi2[y]=mi2[x];
            sum2[y]=sum2[y];
        }else if(mi2[x]+1==mi2[y]){
            sum2[y]+=sum2[x];
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            h=a[2]-a[1];
            if(d<h){
                printf("0\n");
                continue;
            }
            h=d/h;
            if(h>=n-1){
                printf("%lld\n",1ll);
                continue;
            }
            printf("%lld\n",(n-2*h+1)*(h-1)/2+1);
        }
        return 0;
    }
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            mi[i]=mi2[i]=0x3f3f3f3f3f3f3f3f;
            sum[i]=sum2[i]=0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                mi[i]=mi2[i]=0x3f3f3f3f3f3f3f3f;
                sum[i]=sum2[i]=0;
            }
            for(int i=k;i<=n;i++){
                for(int j=i-1;j>=k;j--){
                    if(a[i]-a[j]>d)break;
                    cg(j,i);
                }
            }
            for(int j=1;j<=n;j++){
                if(sum[j]==2ll)ans++;
                cout<<sum[j]<<' ';
            }
            cout<<'\n';
        }
        printf("%lld\n",ans);
    }
    return 0;
}
