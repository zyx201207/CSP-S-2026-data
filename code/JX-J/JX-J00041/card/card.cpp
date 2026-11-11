/*
cha yi bu mei man
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],p[N],vis[N];
int n,m;
void kkk(){
    for(int i=1;i<=m;i++){
        if(vis[i]){
            p[i]++;
            vis[i]=0;
        }
    }
}
void pd(int x){
    for(int i=1;i<=n;i++){
        int d=a[i];
        if(vis[d]){
            for(int j=x;j<=n;j++){
                vis[a[j]]=0;
                if(a[j]==d) break;
            }
        }
        vis[d]=1;
    }
    kkk();
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) pd(i);
    for(int i=1;i<=m;i++){
        if(p[i]) cout<<p[i]<<' ';
    }
    return 0;
}