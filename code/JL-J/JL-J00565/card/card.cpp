#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}
