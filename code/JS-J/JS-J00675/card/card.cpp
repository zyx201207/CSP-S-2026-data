#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]*n;
        if(i!=m){
            cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}
