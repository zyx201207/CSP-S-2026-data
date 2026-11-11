#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (m==1){
        cout<<n;
    }
    else if (m==2){
        cout<<n/2<<" "<<n/2;
    }
    else{
        for (int i=1;i<=m;i++){
            cout<<n<<" ";
        }
    }
    return 0;
}