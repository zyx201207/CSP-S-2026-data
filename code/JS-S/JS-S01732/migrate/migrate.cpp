#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;ll d;
const int N=2e6+10;
ll a[N];
int l[N],r[N];int s[N];
const int N2=310;
bool f1[N2][N2],f2[N2][N2];
void solve1(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            f1[i][j]=f2[i][j]=0;
            if(r[i]==l[j]){
                f1[i][j]=1;
            }
            if(r[i]-1>i&&r[i]==l[j]+1){
                f2[i][j]=1;
            }
        }
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(f1[i][j]) continue;
            for(int k=i+1;k<j;k++){
                if(f1[i][k]&&f1[k][j]){
                    f1[i][j]=1;break;
                }
            }
            if(f1[i][j]) continue;
            for(int k=i+1;k<j;k++){
                if(f2[i][k]&&f1[k][j]||f1[i][k]&&f2[k][j]){
                    f2[i][j]=1;break;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //cout<<i<<' '<<j<<' '<<f1[i][j]<<' '<<f2[i][j]<<'\n';
            ans+=f2[i][j];
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];s[i]=0;
        }
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
            r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            s[l[i]]++;
        }
        if(c<=6){
            solve1();continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(r[i]-1>i){
                ans+=s[r[i]-1];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 1
20 4
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
*/
