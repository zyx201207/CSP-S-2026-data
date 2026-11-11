#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[505];
int g[505][505];
int s[505][505];
vector<int> r[505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            g[a][i]=b;
            r[i].push_back(a);
        }
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            s[i][j]=s[j][i]=1e18;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=0;i<r[k].size()-1;i++){
            for(int j=i+1;j<r[k].size();j++){
                s[r[k][i]][r[k][j]]=s[r[k][j]][r[k][i]]=min(s[r[k][j]][r[k][i]],g[r[k][i]][k]+g[r[k][j]][k]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+s[x][y]<<'\n';
    }
    return 0;
}
//g++ subway.cpp -o subway -std=c++11
/*
We don't talk anymore
We don't talk anymore
We don't talk anymore like we used to do
We don't love anymore
What was all of it for
Oh we don't talk anymore like we used to do
I just heard you find the one you've been looking
You've been looking for
I wish I would have known that wasn't me
Cause even after all this time I still wonder
Why I can't move on
Just the way you did so easily
Don't wanna know
What kinda dress you're wearing tonight
If he's holding onto you so tight
The way I did before
*/