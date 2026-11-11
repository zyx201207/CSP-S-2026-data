#include<bits/stdc++.h>
using namespace std;
int xxx(int ni,int mi){
    int af[1022],b[1022],c[1022],i,j,ans;
    int nx=0,mx=0,cn=ni,cm=mi;
    for(i=1;;i++){
        if(pow(2,nx)>cn&&pow(2,mx)>cm)break;
        if(pow(2,nx)<=cn){
            af[i]=ni%2;
            ni/=2;
            nx++;
        }
        if(pow(2,mx)<=cm){
            b[i]=mi%2;
            mi/=2;
            mx++;
        }
    }
    for(i=max(mx,nx);i>=1;i--){
        if(af[i]==b[i]&&af[i]!=0){
            c[i]=1;
        }
    }
    for(i=max(nx,mx);i>=1;i--){
        c[i-1]+=c[i]*2;
    }
    return c[1];
}
const int maxn=10005;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int i,j,n,m,dp[maxn],a[maxn],l,s,x=1,y=0,c,p;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    if(m==n){
        for(i=1;i<=n;i++){
            if(i==1)l=xxx(a[i],a[i+1]);
            l=xxx(l,a[i+1]);
        }
        cout<<l<<endl;
        return 0;
    }
    if(m==2){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[x]=xxx(a[i],a[j]);
                x++;
            }
        }
        for(i=1;i<=x;i++){
                cout<<dp[i]<<" ";
            y=max(y,dp[i]);
        }
        return 0;
    }
    return 0;
}




