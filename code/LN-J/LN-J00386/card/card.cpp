#include<bits/stdc++.h>

using namespace std;
int n,m;
int pai[1000000];
int vis[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pai[i];
    }
    for(int i=1;i<=n;i++){
        if(pai[i]==1){
            continue;
        }
        cout<<pai[i];
        vis[pai[i]]=1;
    }
    return 0;
}