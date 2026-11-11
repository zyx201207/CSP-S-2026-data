/*#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector< vector<long long> > dp;
int main(){

    int n,m;
    cin>>n>>m;
    a.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i].resize(m+1,0);
    }
    dp[0].resize(m+1,0);
    for(int i=1;i<=n;i++){
        dp[i][1]=max(dp[i-1][1],a[i]);
        for(int j=2;j<=min(m,i);j++){
            dp[i][j]=max(dp[i][j-1]&a[i],dp[i][j]);
        }
    }
    cout<<dp[n][m];
}*/
#include<bits/stdc++.h>
using namespace std;
bool aa=1;
vector<int> a,num,c;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a.resize(n+1);
    c.resize(n+2,0);
    num.resize(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]&&i!=1) aa=0;
    }
    for(int i=1;i<=n;i++){
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0) continue;
        cout<<c[i]<<' ';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
