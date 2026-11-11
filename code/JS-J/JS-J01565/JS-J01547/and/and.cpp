#include <bits/stdc++.h>
using namespace std;
long long maze[2001][2001],used[2001][2001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,x;
    long long maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        maze[i][0]=x;
        maze[0][i]=x;
    }
    if(m==1){
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,maze[i][0]);
        }
        cout<<maxn;
        return 0;
    }
    for(int j=1;j<=n;j++){
        int h=0;
        for(int i=1;i<=n;i++){
            if(i!=j){
                maze[i][j]=maze[i][0]&maze[0][j];
                    maxn=max(maxn,maze[i][j]);
                }
            }
        for(int i=1;i<=n;i++)
        {
            if(maze[i][j]==maxn&&h==0){
                used[i][j]=1;
                h=1;
            }
            else{
                maze[i][j]=maxn;
            }
        }
    }
    cout<<maxn;
    return 0;
}
