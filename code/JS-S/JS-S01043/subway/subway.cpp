#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[100005];
long long a[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i][x]=y;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long sum1=w[x]+a[x][x]+a[x][y]+w[y];
        long long sum2=w[x]+a[x][x]+a[x][(x+y+1)/2]+a[(x+y+1)/2][(x+y+1)/2]+a[(x+y+1)/2][y]+w[y];
        if(q%2==0){
            cout<<sum1<<"\n";
        }
        else{
            cout<<sum2<<"\n";
        }
    }
    return 0;
}
