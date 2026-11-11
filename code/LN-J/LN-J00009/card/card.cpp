#include<bits/stdc++.h>
using namespace std;
int a[10000001],s[10000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int max_a=-1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
        max_a=max(max_a,a[i]);
    }
    for(int i=1;i<=max_a;i++){
        cout<<s[i]<<' ';
    }
    return 0;
}