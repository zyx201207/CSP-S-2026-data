include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int w[N],a[501][101],t[501][101],cnt[N],s[1e5],e[1e5];
int main(){
    freopen("subway.in","r",stdin);
    freoprn("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cnt[i];
        for(int j=1;j<=cnt[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s[i]>>e[i];
    }
    for(int i=1;i<=q;i++){

    }

    return 0;
}
