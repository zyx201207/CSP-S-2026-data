#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector< vector<long long> >dp;
bool aa=1,bb=1,cc=1;
long long maxn=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m!=1) cc=0;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxn) maxn=a[i];
        //if(a[i]!=i-1) bb=0;
    }
    //if(bb==1) cout<<(n>>1)-1;
    if(cc) cout<<maxn;
    else{
        dp.resize(n+1);
        dp[0].resize(m+1,0);
        for(int i=1;i<=n;i++){
            dp[i].resize(m+1,0);
            dp[i][1]=max(dp[i-1][1],a[i]);
            for(int j=2;j<=min(m,i);j++){
                dp[i][j]=max(dp[i][j-1]&a[i],dp[i][j]);
            }
        }
        cout<<dp[n][m];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> dp;

int main(){
    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a.resize(n+1);
    dp.resize(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp[1]=a[i];
        for(int j=min(m,i);j>=2;j--){
            dp[j]=max((dp[j-1]&a[i]),dp[j]);
        }
    }
    cout<<dp[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}*/
