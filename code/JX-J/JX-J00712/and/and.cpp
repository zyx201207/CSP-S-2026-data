#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[100][200100],x[200100],remb[200100],outd[200100],maxx=0,ans=0,sm=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        int c=a;
        while(c){
            b[++x[i]][i]=c%2;
            c/=2;
        }
        maxx=max(maxx,x[i]);
    }
    for(int i=1;i<=n;i++)for(int j=x[i];j>=1;j--)swap(b[j+maxx-x[i]][i],b[j][i]);
    for(int i=2;i<=maxx;i++)sm*=2;
    for(int i=1;i<=maxx;i++){
        int sx=0;
        for(int j=1;j<=n;j++)if(b[i][j]==1&&outd[j]==0){
            remb[j]=1;
            sx++;
        }
        if(sx>=m){
            ans+=sm;
            for(int j=1;j<=n;j++){
                if(remb[j]==0)outd[j]=1;
            }
        }
        for(int j=1;j<=n;j++)remb[j]=0;
        sm/=2;
    }
    cout<<ans;
    return 0;
}
