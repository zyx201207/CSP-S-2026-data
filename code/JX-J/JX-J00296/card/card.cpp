#include<bits/stdc++.h>
using namespace std;
int n,m;
int pa[500005],desk[500005],ans[300005];
void df(int u){
    for(int x=1;x<=sizeof(desk);x++){
        if(desk[x]==u){
             for(int i=x+1;i<=sizeof(desk);i++){
                pa[i]=0;
             }
             return;
        }
    }
    desk[sizeof(desk)+1]=u;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pa[i];
    }
    int q=1;
    while(q<=n){
        for(int i=q;i<=n;i++){
            df(pa[i]);
        }
        for(int i=1;i<=sizeof(desk);i++){
            ans[desk[i]]++;
        }
        q++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
