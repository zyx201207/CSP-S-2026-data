#include<bits/stdc++.h>
using namespace std;
long long gzy[16000][16000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    long long a;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a;
        gzy[i][m]=gzy[i-1][m];
        for (int j=min(m,i);j>=1;j--){
            if (j==1) gzy[i][j]=a;
            else {
                for (int k=1;k<=i-1;k++)
                gzy[i][j]=max(gzy[k][j-1]&a,gzy[i][j]);
            }
       }
    }
   cout<<gzy[n][m];
    return 0;
}
