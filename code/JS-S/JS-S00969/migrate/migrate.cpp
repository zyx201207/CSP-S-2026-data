#include<bits/stdc++.h>
#define ll long long
const int N=2e6+5;
using namespace std;
int n;
ll a[N],d;
int lt[N],dp[N][4];
//0:1 1
//1:1 >1
//2:2
//3:1 \
//4:1 1 \
//5:2 \

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cc,T;
    cin>>cc>>T;
    for (int id=1;id<=T;id++){
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++){
            lt[i]=dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
        }
        int t=1;
        for (int i=1;i<=n;i++){
            while (a[i]-a[t]>d) t++;
            lt[i]=t;
        }
        lt[n+1]=n+1;
        ll sum=0;
        for (int i=2;i<=n;i++){
            int x=lt[i],y=lt[i+1],z=min(i,lt[i+2]);
            if (x==i-1) dp[i][3]=dp[i-1][3];
            else dp[i][3]=dp[x][0];
            sum+=dp[i][3];
            if (x==y&&y==z||x==i) continue;
            if (y==i) dp[i][0]=dp[i][3];
            else if (x==y) dp[i][0]=dp[x][2]+z-y;
            else if (x==y-1) dp[i][0]=dp[x][1]+z-y;
            else dp[i][0]=dp[x][0]+z-y;
            if (x==y) continue;
            dp[i][1]=dp[x][1];
            dp[i][2]=dp[x][2]+y-x;
        }
        cout<<sum<<'\n';
    }
}
/*

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
