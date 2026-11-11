#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int Max=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        Max=max(Max,a);
    }
    cout<<Max;
    return 0;
}
