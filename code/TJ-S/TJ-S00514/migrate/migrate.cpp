#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6;
int c,t,n;
ll d,x[N+5];
void solveA(){
    while (t--){
        scanf("%d%Ld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%Ld",&x[i]);
        }
        ll c=x[2]-x[1];
        //cout<<n<<" "<<d<<" "<<c<<"\n";
        if (d<2*c)cout<<"0\n";
        else cout<<max(0ll,n-(d/c)*2+1)<<"\n";
    }
    return ;
}
void solveB(){
    while (t--){
        scanf("%d%Ld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%Ld",&x[i]);
        }
        int r=1,l=1;
        ll ans=0;
        for (;r<=n;r++){
            while (l<r&&x[r]-x[l]>d)l++;
            if (l==r-2)ans+=l-1;
        }
        cout<<ans<<"\n";
    }
    return ;
}
int dist[5009][5009][2],to[5009];
void solvel(){
    while (t--){
        scanf("%d%Ld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%Ld",&x[i]);
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++)dist[i][j][0]=dist[i][j][1]=-1;
        }
        for (int i=1;i<n;i++){
            if (x[i+1]-x[i]<=d)dist[i][i+1][0]=1,dist[i][i+1][1]=i;
        }
        int pd=1;
        for (int i=3;i<=n;i++){
            if (dist[i-1][i][0]==-1){pd=i;continue;}
            for (int j=pd;j<=i-2;j++){
                if (x[i]-x[dist[j][i-1][1]]<=d)dist[j][i][0]=dist[j][i-1][0],dist[j][i][1]=dist[j][i-1][1];
                else dist[j][i][0]=dist[j][i-1][0]+1,dist[j][i][1]=i-1;
            }
        }
        ll ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+2;j<=n;j++){
                if (dist[i][j][0]==-1)break;
                ll cnt=0;
                for (int k=i+1;k<j;k++){
                    if (dist[i][j][0]==dist[i][k][0]+dist[k][j][0])cnt+=(to[dist[i][k][0]]>=1),to[dist[i][k][0]]++;
                }
                //cout<<i<<" "<<j<<" "<<dist[i][j][0]<<" "<<cnt<<"\n";
                if (cnt==1)ans++;
                for (int k=i+1;k<j;k++){
                    if (dist[i][j][0]==dist[i][k][0]+dist[k][j][0])to[dist[i][k][0]]=0;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if (c==11||c==12){solveA();return 0;}
    if (c==13||c==14){solveB();return 0;}
    solvel();
    return 0;
}

