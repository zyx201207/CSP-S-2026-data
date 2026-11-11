#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }

    return 0;
}
