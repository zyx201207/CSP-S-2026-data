#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,ans,x[N],k[N],s[N];
int check1(int x,int y){
    int l=x,r=y;
    while(l<=r){
        int mid=l+r>>1;
        if(s[mid]-s[x]<=d) l=mid+1;
        else r=mid-1;
    }
    if(l-1>=x&&l-1<=y) return l-1;
    else return -1e18;
}
int check2(int x,int y){
    int l=x,r=y;
    while(l<=r){
        int mid=l+r>>1;
        if(s[y]-s[mid]<=d) r=mid-1;
        else l=mid+1;
    }
    if(l>=x&&l<=y) return l;
    else return -1e17;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            k[i]=x[i]-x[i-1];
        }
        if(n==1){
            printf("%d",0);
            continue;
        }
        if(c==0||c==11||c==12){
            int w=d/(x[2]-x[1]);
            if(w!=1) printf("%lld\n",max(n-(w*2-1),(long long)0));
            else printf("%d\n",0);
            continue;
        }
        for(int i=2;i<=n;i++){
            s[i]=s[i-1]+k[i];
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[j]-s[i]<=d) continue;
                int x=check1(i,j);
                int y=check2(i,j);
                if(x-1==y) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
