#include<bits/stdc++.h>
using namespace std;

int main (){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<m;i++) cin >>w[i];
    long long dp[m+1][m+1][n+1];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                dp[i][j][k]=INT_MAX;
    for(int i=0;i<n;i++){
        int k;
        cin >>k;
        vector<int> a;
        vector<int> t;
        for(int j=0;j<k;j++){
            int temp_a,temp_t;
            cin >>temp_a>>temp_t;
            a.push_back(temp_a);
            t.push_back(temp_t);
        }
        for(int l=0;l<k;i++)
            for(int j=0;j<k;j++){
                dp[a[j]][a[l]][i]=t[j];
                dp[a[l]][a[j]][i]=t[j];
            }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin >>x>>y;
        long long ans=LLONG_MAX;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;j++){
                for(int k=1;k<=m;k++){
                    ans=min(ans,w[i]+dp[x][k][j]+dp[k][k][j]+dp[k][k][l]+dp[k][y][l]+w[l]);
                }
            }
        }
        cout<<ans<<endl;
    }
    //for(int k=0;k<=n;k++){
    //    for(int i=1;i<=m;i++){
    //        for(int j=1;j<=m;j++)
    //            cout<<dp[i][j]<<" ";
    //        cout<<endl;
    //    }
    //    cout<<endl;
    //}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
