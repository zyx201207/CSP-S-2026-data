#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    int b[1000005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    cout<<b[m];

    return 0;
}
