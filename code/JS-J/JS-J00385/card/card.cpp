#include<bits/stdc++.h>
using namespace std;
int a[500010],wz[300019];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cout<<n<<' ';
    }
    return 0;
}
