#include<bits/stdc++.h>
using namespace std;
int b[5005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[5001];
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i];
    }
    return 0;
}
