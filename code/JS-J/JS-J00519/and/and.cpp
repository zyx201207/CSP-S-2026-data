#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
const int MAXLG=30;
int n,m,a[MAXN];
int ans;
bool f[MAXN];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=1;
    }
    for(int i=MAXLG;i>=0;i--){
        int t=0;
        for(int j=1;j<=n;j++){
            if(!f[j])continue;
            t+=((a[j]>>i)&1);
        }
        if(t>=m){
            for(int j=1;j<=n;j++){
                if(!f[j])continue;
                if(!((a[j]>>i)&1))f[j]=0;
            }
            ans|=(1<<i);
        }
    }
    cout<<ans;
    return 0;
}
//g++ and.cpp -o and -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576 && ulimit -s 1048576 && time ./and