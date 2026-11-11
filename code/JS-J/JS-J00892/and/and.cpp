#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;int f[2005][2005];int m;int a[200005];
int f1[200005];
int f2[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
        if(a[i]>=4)flag=0;
    }

    if(m==n){//+5pts
        int tnt=a[1];
        for(int i=2LL;i<=n;i++){
            tnt&=a[i];
        }
        cout<<tnt;
        return 0;
    }

    else if(m==n-1LL){//+10pts
        // qian zhui he jia shang hou zhui he
        f1[1]=a[1];f2[n]=a[n];
        for(int i=2;i<=n;i++){
            f1[i]=f1[i-1]&a[i];
        }
        for(int i=n-1;i>=1;i--){
            f2[i]=f2[i+1]&a[i];
        }
        int ans=0LL;
        ans=max({ans,f1[n-1],f2[2]});
        for(int i=2;i<=n-1;i++){
            ans=max(ans,f1[i-1]&f2[i+1]);
        }
        cout<<ans;
        return 0;
    }
    else if(flag){//+10pts
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==3){
                cnt++;
            }
        }
        if(cnt>=m){
            cout<<3;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==2){
                cnt++;
            }
        }
        if(cnt>=m){
            cout<<2;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i][1]=a[i];
    }
    for(int i=1;i<=n;i++){//+45pts
        for(int j=1;j<=m;j++){
            for(int k=1;k<i;k++){
                f[i][j]=max(f[k][j-1]&a[i],f[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1LL;i<=n;i++){
        ans=max(f[i][m],ans);
    }
    cout<<ans;
}//freopen 
//114514 luogu:lontengfeiwu2012
//m=1,m=n,m=2  ,n<=20bao li dp,m=n-1,m<=4
//zhe me duo zuo diao ying gai you 70pts
//n<=2*10^5 jiu ting tian you ming ba,bu zhi dao zhe ge DP ke yi na zou ji fen,jia you,ping ce ji!