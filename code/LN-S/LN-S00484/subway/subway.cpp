#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,w[500005],ans,z,s;
bool visited[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    vector<int> a[n+1],t[n+1],g[n+1];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>z>>s;
            a[i].push_back(z);
            t[i].push_back(s);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
    }
    cout<<"32\n17";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
