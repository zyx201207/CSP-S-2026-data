#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005];
int k[100005];
int ans;
vector<int>a[100005];
map<int,int>t[100005];
map<int,int>l[100005];

void df(int x1,int y1){
    cin>>x1>>y1;
    return ;
}
void solve(){
    ans=0;
    int x,y;
    cin>>x>>y;
    int ti=0;
}
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        /*for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[k][i]=y;
        }
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].size();j++){
            for(int k=j;k<=a[i].size();k++){
                l[j][k]=l[k][j]=t[j][i]+t[k][i];
            }
        }
    }


    while(m--)solve();
    return 0;
}
}
