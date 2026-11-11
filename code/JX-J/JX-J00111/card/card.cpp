#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k[300005];
void f(int t){
    bool b[300005];
    for(int i=1;i<=m;i++) b[i]=false;
    for(int i=t;i<=n;i++){
        b[a[i]]=true;
    }
    for(int i=1;i<=m;i++){
        if(b[i]==true) k[i]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f(i);
    }
    for(int i=1;i<=m;i++) cout<<k[i]<<" ";
    return 0;
}
