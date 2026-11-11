#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q,k,x,y;
long long ans;
int w[N],a[510][1010],t[510][1010];
struct Node{
    int id,wv;
}b[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int v=1;v<=m;v++) cin>>w[v];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        b[i].id=i;
        b[i].wv=w[i];
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=ans+w[x]+w[y];
    }
    cout<<ans<<endl;
    return 0;
}
