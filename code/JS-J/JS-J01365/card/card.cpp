#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[100005];

int main(){
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]){
            cout<<i<<" ";
        }
    }
    return 0;
}
