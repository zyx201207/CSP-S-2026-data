#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ax,tx,x,y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    vector<int> k(n);vector<int> vis(n);
    vector<int> a[n],t[n],b[n],z[n];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>ax>>tx;
            a[i].push_back(ax);
            b[ax].push_back(i);
            t[i].push_back(tx);
            z[ax].push_back(tx);
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<t[x][b[x][0]]+t[y][b[y][0]]+w[x]+w[y]<<endl;
    }
}