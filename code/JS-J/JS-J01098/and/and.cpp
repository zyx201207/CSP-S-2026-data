#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,x,ans;
bool b[N][31],bad[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>x;
        int y=0;
        while(x){
            b[i][++y]=x%2;
            x>>=1;
        }
    }
    for(int i=30;i>0;--i){
        ans<<=1;
        int k=0;
        for(int j=1;j<=n;++j){
            if(bad[j]) continue;
            if(b[j][i]) ++k;
        }
        if(k>=m){
            ++ans;
            for(int j=1;j<=n;++j){
                if(bad[j]) continue;
                if(!b[j][i]) bad[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
