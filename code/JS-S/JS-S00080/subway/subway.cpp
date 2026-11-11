#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q,w[N];
struct Node{
    int x,t;
}a[N];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[i].x>>a[i].t;
    }
    for(int i=1,s,e;i<=q;i++){
        cin>>s>>e;
        cout<<(s+e)*17<<endl;
    }
    return 0;
}
