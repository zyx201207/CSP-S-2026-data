#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
using namespace std;

const int M=2e6+3;

int cas,n,d,x[M];
int a[5003][5003];

int fndr(int pl,int pr){
    int l=pl+1,r=pr-1,mid,ret=n+1;
    while(l<=r){
        mid=(l+r)>>1;
        if(x[mid]-x[pl]<=d){
            l=mid+1;
            ret=mid;
        }else{
            r=mid-1;
        }
    }
    return r;
}
int fndl(int pl,int pr){
    int l=pl+1,r=pr-1,mid,ret=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(x[pr]-x[mid]<=d){
            r=mid-1;
            ret=mid;
        }else{
            l=mid+1;
        }
    }
    return ret;
}

bool chk(int l,int r){
    if(x[r]-x[l]<=d)return 0;
    int rpos=fndr(l,r);
    int lpos=fndl(l,r);
    //printf("%lld~%lld : %lld %lld\n",l,r,rpos,lpos);
    return rpos-lpos==1;
}

void solve(){
    scanf("%lld%lld",&n,&d);
    //printf("%lld %lld ",n,d);
    For(i,1,n){
        scanf("%lld",&x[i]);
        For(j,1,n){
            a[i][j]=0;
        }
    }
    if(n<=3){
        printf("0\n");
        return ;
    }
    if(cas<=10){//n<=300 24pts n^3
        int ans=0;
        For(len,4,n){
            For(i,1,n-len+1){
                int j=i+len-1,l=i,r=i+len-1;
                while(a[l][r]==0 and r-l>=3 and (x[l+2]-x[l]>d and x[l+1]-x[l]<=d or x[l+3]-x[l+1]>d and x[l+2]-x[l]<=d))l++;
                while(a[l][r]==0 and r-l>=3 and (x[r]-x[r-2]>d and x[r]-x[r-1]<=d or x[r-1]-x[r-3]>d and x[r]-x[r-2]<=d))r--;
                if(a[l][r]){
                    //cout<<777;
                    a[i][j]=a[l][r];
                    if(a[i][j]==1)ans++;
                }else if(r-l>=3 and chk(l,r)){
                    //cout<<888;
                    ans++;
                    a[i][j]=1;
                }else{
                    //cout<<999;
                    a[i][j]=-1;
                }
                //printf("%lld %lld: %lld\n",i,j,(int)a[i][j]);
            }
        }
        printf("%lld\n",ans);
        return ;
    }
    if(cas==11 or cas==12){//spA 8pts
        int c=x[2]-x[1];
        //printf("%lld \n",c);
        d=d/c;
        if(d<2){
            printf("0\n");
            return ;
        }
        printf("%lld\n",max(0ll,n-2*d+1));
        return ;
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _;scanf("%lld%lld",&cas,&_);
    while(_--){
        solve();
    }
    return 0;
}

/*
froepen
chzx_AT AK NGOI!!!!!
*/
