#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a[N];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[n]<<endl;
    return 0;
}