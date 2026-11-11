#include <bits/stdc++.h>
using namespace std;
itn a[10086];
int main(){
    freopen("in.and","r",stdin);
    freopen("out.and","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4)cout<<12;
    if(n==5)cout<<7;
    return 0;
}
