#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
int f[50][500001];
set<int>useful[2];
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int top=-1;
        while(a[i]){
            f[++top][i]=a[i]%2;
            a[i]/=2;
        }
    }
    int nowpow,Class=0;
    for(int i=30;i;i--){
        int ok=0;
        for(int j=1;j<=n;j++){
            if(f[i][j]){
                ok++;
                useful[1].insert(j);
            }
        }
        if(ok>=m){
            nowpow=i;
            break;
        }else{
            useful[1].clear();
        }
    }
    ans+=pow(2,nowpow);
    for(int i=nowpow-1;i>=0;i--){
        int ok=0;
        for(auto j:useful[Class^1]){
            if(f[i][j]){
                ok++;
                useful[Class].insert(j);
            }
        }
        if(ok>=m){
            ans+=pow(2,i);
            useful[Class^1].clear();
            Class^=1;
        }else{
            useful[Class].clear();
        }
    }
    cout<<ans;
}
