#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d;
int a[2000010];
int posl[2000010],posr[2000010],nxtl[2000010],nxtr[2000010];
int f[5010][5010],sum[5010][5010];
int now[5010];
void init(){
    int now=1;
    for(int i=1;i<=n;i++){
        for(;now<=n&&a[now]-a[i]<=d;now++);
        nxtr[i]=now-1;
    }
    now=n;
    for(int i=n;i>0;i--){
        for(;now>0&&a[i]-a[now]<=d;now--);
        nxtl[i]=now+1;
    }
}
int solve0(){
    for(int i=1;i<=n+1;i++){
        now[i]=0;
        for(int j=1;j<=n+1;j++){
            f[i][j]=sum[i][j]=0;
        }
    }
    for(int i=n;i>0;i--){
        for(int j=n;j>i;j--){
            if(nxtl[now[j]]>i){
                now[j]=nxtl[now[j]];
            }
            if(j<=nxtr[i]) f[i][j]=1;
            else f[i][j]=sum[now[j]][j]-sum[nxtr[i]+1][j];
            sum[i][j]=sum[i+1][j]+f[i][j];
        }
        f[i][i]=sum[i][i]=1;
        now[i]=i;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]==2) res++;
        }
    }
    return res;
}
int solve1(){
    int dif=a[2]-a[1];
    if(d<dif) return 0;
    d/=dif;
    if(d==1) return 0;
    if(n<=2*d-1) return 0;
    return n-(2*d-1);
}
// int solve2(){
//     int p=0;
//     for(int i=1;i<=n;i++){
//         if(nxtl[i]==1&&nxtr[i]==n){
//             p=i;
//             break;
//         }
//     }

// }
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<"0\n";
            continue;
        }
        init();
        if(c<=10){
            cout<<solve0()<<'\n';
            continue;
        }
        if(c<=12){
            cout<<solve1()<<'\n';
            continue;
        }
        cout<<solve0()<<'\n';
        // if(c<=14){
        //     cout<<solve2()<<'\n';
        // }
    }
}