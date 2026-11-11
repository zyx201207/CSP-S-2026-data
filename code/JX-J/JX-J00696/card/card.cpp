#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n],b[m+1],c[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cout<<(c[i]-1)%n+1<<' ';
    }
}
