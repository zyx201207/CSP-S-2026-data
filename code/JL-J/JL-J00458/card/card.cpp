#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,num[500000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        cout<<num[i];
    }
    return 0;
}
