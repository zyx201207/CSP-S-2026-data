#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,nu;
int w[100005];
struct node{
    int l;
    int s[100005];
    int t[100005];
}a[500];
struct fun{
    int q;
    int z;
}p[100005];
int kru(int q,int z,int m,int n,int w[100005]){
    int ans;
    int x[m][n];
    for(int j=1;j<=n;j++){
        for(int k=1;k<=a[n].l;k++){
            x[a[j].s[k]][j]==a[n].t[k];
        }
    }
    for(int i=q;i<=z;i++){
        for(int j=1;j<=n;j++){
            ans+=min(x[i][j],x[i][j-1]);
        }
    }
    ans+=w[q]+w[z];
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>nu;
    for(int i=1;i<=m;i++){
        cin>>w[m];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].l;
        for(int j=1;i<=a[i].l;j++){
            cin>>a[i].s[j]>>a[i].t[j];
        }
    }
    for(int i=1;i<=nu;i++){
        cin>>p[i].q>>p[i].z;
    }
    for(int i=1;i<=nu;i++){
        cout<<kru(p[100005].q,p[100005].z,m,n,w)<<endl;
    }
    return 0;
}
