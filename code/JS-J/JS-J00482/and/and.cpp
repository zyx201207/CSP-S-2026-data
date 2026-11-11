#include<bits/stdc++.h>
using namespace std;
int n,a[200009],cnt=0,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt++;
    }
    cout<<a[cnt];
    return 0;
}


