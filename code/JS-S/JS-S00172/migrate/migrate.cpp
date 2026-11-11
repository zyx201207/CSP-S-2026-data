#include<bits/stdc++.h>
using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

const int maxn=1e5+10;
const int inf=1e9;

void solve(){
    int n,d;
    fin>>n>>d;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)fin>>a[i];

    vector<vector<int>>dist(n+10,vector<int>(n+10,inf));
    vector<vector<int>>way(n+10,vector<int>(n+10,inf));
    int ans=0;
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
        way[i][i]=1;
        for(int j=i+1;j<=n;j++){
            int from=j-1;
            int nway=0;
            while(from>0&&a[j]-a[from]<=d){
                if(dist[i][from]+1<dist[i][j]){
                    dist[i][j]=dist[i][from]+1;
                    nway=way[i][from];
                }
                else if(dist[i][from]+1==dist[i][j]){
                    nway+=way[i][from];
                }
                from--;
            }
            way[i][j]=nway;
            if(way[i][j]==2)ans++;
        }
    }
    fout<<ans<<"\n";
}

int main(){
    int c,t;
    fin>>c>>t;
    while(t--)solve();
}