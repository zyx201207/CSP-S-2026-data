#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+10]={};
    int b[n+10]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
