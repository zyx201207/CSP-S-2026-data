#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=2e5+5;
int a[M],b[M],dp[N][N],las[M],suf[M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    las[0]=suf[n+1]=INT_MAX;
    bool flag=1,flag4=1;
    for(int i=1;i<=n;i++){
        cin>>a[i],dp[1][i]=a[i],las[i]=las[i-1]&a[i],b[i]=a[i];
        int tmp=a[i];
        bool flag2=1;
        while(tmp){
            if(!(tmp&1)){
                flag2=0;
                break;
            }
            tmp>>=1;
        }
        if(a[i]>=4)flag4=0;
        flag=flag&&flag2;
    }
    sort(b+1,b+1+n);
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]&a[i];
    if(n==m){
        cout<<las[n]<<endl;
        return 0;
    }
    if(m==n-1){
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,las[i-1]&suf[i+1]);
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        cout<<b[n]<<endl;
        return 0;
    }
    if(flag){
        int ans=INT_MAX;
        for(int i=1;i<=m;i++)ans=ans&b[n-i+1];
        cout<<ans<<endl;
        return 0;
    }
    bool flag2=1;
    for(int i=1;i<=n;i++){
        if(b[i]!=i-1){
            flag2=0;
            break;
        }
    }
    bool flag3=1;
    int tmp=n-1;
    while(tmp){
        if(!(tmp&1)){
            flag3=0;
            break;
        }
        tmp>>=1;
    }
    if(flag2&&flag3){
        int ans=INT_MAX;
        for(int i=1;i<=m;i++)ans=ans&b[n-i+1];
        cout<<ans<<endl;
        return 0;
    }
    if(flag4){
        vector<int>ttttt(4);
        for(int i=1;i<=n;i++)ttttt[a[i]]++;
        if(ttttt[3]>=m)cout<<3<<endl;
        else if(ttttt[3]+ttttt[2]>=m)cout<<2<<endl;
        else if(ttttt[3]+ttttt[1]>=m)cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<j;k++){
                dp[i][j]=max(dp[i-1][k]&a[j],dp[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[m][i]);
    cout<<ans<<endl;
    return 0;
}