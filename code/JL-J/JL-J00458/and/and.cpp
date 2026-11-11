#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num[200000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    cout<<num[n];
    return 0;
}
