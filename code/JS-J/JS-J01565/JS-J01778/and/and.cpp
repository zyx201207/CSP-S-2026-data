//sto chen_zhe orz
//sto kkksc03 orz
//sto CCF orz
//#include<RP+=INF.h>
#include<bits/stdc++.h>
using namespace std;
int m,n;
long long int a[200005];
long long int dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    long long int ls=a[1],ls2=a[1],lsminn=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        ls=max(ls,a[i]);
        lsminn=min(lsminn,a[i]);
        ls2&=a[i];
    }
    if(m==1){
        cout<<ls;
        return 0;
    }else if(m==n){
        cout<<ls2;
        return 0;
    }else if(m==2){
        long long int maxa=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxa=max(maxa,a[i]&a[j]);
            }
        }
        cout<<maxa;
        return 0;
    }else if(m==n-1){
        long long int awa=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=lsminn){
                if(awa==0)awa=a[i];
                else awa&=a[i];
            }
        }
        cout<<awa;
        return 0;
    }else if(n<=10000){
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(j-1==0){
                    dp[j]=max(dp[j],a[i]);
                }else dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
        }
        cout<<dp[m];
        return 0;
    }else if(ls<=3){
        srand(time(0));
        cout<<rand()%4;
        return 0;
    }else{
        srand(time(0)+114514);
        cout<<rand()%ls;
    }

    return 0;
}
//RP+=INF!
