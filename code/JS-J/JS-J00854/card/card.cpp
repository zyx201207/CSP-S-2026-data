#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10000000000]={0};
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
    }
    int c=0;
    for(int i=1;i<=x;i++){
        c+=a[i];
        cout<<c<<' ';
    }
    return 0;
}
