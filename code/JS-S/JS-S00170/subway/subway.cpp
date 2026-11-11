#include<bits/stdc++.h>
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
int c,n,m,d,q;
int w[500100];
int k[5000];
int a[5010][5010];
int t[5010][5010];
int dp[5010][5010];
int main(){
    fin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        fin>>w[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=2147483647;
            dp[j][i]=2147483647;
        }
    }
    for(int s=0;s<n;s++){
        fin>>k[s];
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                fin>>a[i/2][k[s]];
            }
            else{
                fin>>t[(i-1)/2][k[s]];
                for(int p=1;p<n;p++){
                    dp[a[i/2][k[s]]][a[p][k[s]]]=min(dp[a[i/2][k[s]]][a[p][k[s]]],t[(i-1)/2][k[s]]+t[p][k[s]]);
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        fin>>x>>y;
        fout<<min(dp[x][y],dp[y][x])<<"\n";
    }
}
