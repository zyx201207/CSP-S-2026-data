#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int cnt[N];
int n,d;
void dfs(int x,int y,int cs){
    if(x==y){
        cnt[cs]++;
        //cout<<cs<<endl;
        return ;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d){
            dfs(i,y,cs+1);
        }
    }
    return ;
}
void solve1(){
    long long ans=0;
    for(int i=1;i<=n-2;i++){
        for(int j=i+2;j<=n;j++){
            memset(cnt,0,sizeof cnt);
            //cout<<i<<" "<<j<<endl;
            dfs(i,j,0);
            int k=0;
            while(cnt[k]==0){
                k++;
            }
            if(cnt[k]==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha=a[2]-a[1];
        bool A=1;
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]!=cha){
                A=0;
            }
        }
        if(n<=9){
            solve1();
        }
        else if(A==1){
            long long b=d/cha;
            if(b<=1){
                cout<<0<<'\n';
            }
            else{
                long long ans=0;
                ans=max(n+1-2*b,0ll);
                cout<<ans<<'\n';
            }
        }
        else{
            long long b=d/cha;
            if(b<=1){
                cout<<0<<'\n';
            }
            else{
                long long ans=0;
                ans=max(n+1-2*b,0ll);
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}
