#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500,MAXM=500005,MAXQ=100005;
int c,n,m,d,Q;
int w[MAXM];
int a[MAXN][MAXM],t[MAXN][MAXM];
struct node{
    int l,r;
}q[MAXQ];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=Q;i++){
        cin>>q[i].l>>q[i].r;
    }

    return 0;
}//dui pai T1!!!!!!!!!!!!!!!!!!!!!!!
// g++ subway.cpp -o subway -std=c++14 -O2