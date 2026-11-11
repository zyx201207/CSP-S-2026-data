#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+500;
mt19937 rad((0xC3+0xC5)>>1);
int c,T,n,rp[N],lln[N],rln[N];ll d,x[N];
struct node{
    int v,c;node():v(),c(){}node(int t,int y):v(t),c(y){}
    node&operator+=(const node&a){
        if(v>a.v)return*this=a;
        if(v==a.v)c+=a.c;
        return*this;
    }
}f[N];
void work(){
    cin>>n>>d;
    memset(x,0,(n+5)*sizeof(ll));
    bool flg=1;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        flg&=(i<=2||x[i]-x[i-1]==x[i-1]-x[i-2]);
    }
    for(int i=1,j=1;i<=n;i++){
        while(j<n&&x[j+1]-x[i]<=d)j++;
        rp[i]=j;
    }

    ll ans=0;
    if(flg){
        f[1]={1,1};
        for(int j=2,k=1,k2=0,sum=0;j<=n;j++){
            if(x[j]-x[j-1]>d)break;
            f[j]={N,0};
            while(k<j-1&&rp[k]<j)k++,sum-=f[k].c;
            if(k2<k)k2=k-1,sum=0;
            while(k2<j-1&&f[k2+1].v==f[k].v)sum+=f[++k2].c;
            f[j]={f[k].v+1,sum};
            if(sum==2)ans+=(n-j+1);
        }
    }else{
        for(int i=1;i<=n;i++){
            f[i]={1,1};
            for(int j=i+1,k=i,k2=i-1,sum=0;j<=n;j++){
                if(x[j]-x[j-1]>d)break;
                f[j]={N,0};
                while(k<j-1&&rp[k]<j)k++,sum-=f[k].c;
                if(k2<k)k2=k-1,sum=0;
                while(k2<j-1&&f[k2+1].v==f[k].v)sum+=f[++k2].c;
                f[j]={f[k].v+1,sum};
                if(sum==2)ans++;
            }
        }
    }

    cout<<ans<<'\n';

    // for(int i=1;i<=n;i++){
    //     int l=i;
    //     while(l&&rp[l]>i)l--;
    //     if(l){
    //         lln[i]=l+1;
    //         while(l>1&&(rp[l-1]==i||rp[l-1]==l))l--;
    //     }else lln[i]=0;
    //     int r=rp[i-1]+1;
    //     if(r<=n){
    //     }else r=

    //     while(l>1&&x[l]-x[l-1]<=d&&x[l+1]-x[l-1]>d)l--;
    //     while(r<n&&x[r+1]-x[r]<=d&&x[r+1]-x[r-1]>d)r++;
    //     lln[i]=l,rln[i]=r;
    //     cerr<<i<<' '<<lip[i]<<' '<<rip[i]<<'\n';
    // }

    // cerr<<"t2:\n";
    // for(int i=1;i<=n;i++)
    //     for(int j=i+1;j<=rp[i];j++){
    //         for(int k=max(rp[i]+1,j+2);k<=rp[j];k++){
    //             bool chk1=(j==i+1||rp[j-1]<k);
    //             bool chk3=(j+1<=rp[i]);
    //             bool chk2=(k==j+2||rp[i]<j+2);
    //             if(chk1&&chk2&&chk3){
    //                 cerr<<i<<' '<<k<<"\n";
    //                 ans+=1ll*lip[i]*rip[k];
    //             }
    //         }
    //     }
    // // for(int i=1;i<=n;i++)for(int j=i+3;j<=n;j++)if(x[j]-x[i]>d){
    // //     int ct=0;
    // //     for(int p=i+1;p<j&&ct<2;p++)
    // //         for(int q=p+1;q<j&&ct<2;q++){
    // //             if(x[q]-x[i]<=d&&x[j]-x[p]<=d){
    // //                 if(++ct>1)break;
    // //             }
    // //         }
    // //     if(ct==1){
    // //         int l=i,r=j;
    // //         while(l>1&&x[l]-x[l-1]<=d&&x[l+1]-x[l-1]>d)l--;
    // //         while(r<n&&x[r+1]-x[r]<=d&&x[r+1]-x[r-1]>d)r++;
    // //         for(int a=l;a<=i;a++)for(int b=j;b<=r;b++)cerr<<a<<','<<b<<"\n";
    // //         // ans+=1ll*(i-l+1)*(r-j+1);
    // //     }
    // // }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(cin>>c>>T;T--;)work();
    cout.flush();
    return 0;
}