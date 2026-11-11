#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx[200005];
int maxcnt=0;
//int dp[65537][16385];
int dp[2][200005];
bool fsx=0;
int ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int nowmax=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nowmax=max(a[i],nowmax);
        maxx[++maxcnt]=nowmax;
    }
    maxcnt=0;
    for(int i=1;i<=n;i++){
        fsx=!fsx;
        dp[(int)(fsx)][1]=maxx[++maxcnt];
        for(int j=2;j<=i;j++){
            dp[(int)(fsx)][j]=max(dp[(int)(fsx)][j-1]&a[i],dp[(int)(!fsx)][j-1]&a[i]);
            //cout<<dp[(int)(fsx)][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[(int)(fsx)][m]<<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
