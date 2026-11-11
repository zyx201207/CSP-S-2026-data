#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],tong[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        tong[a[i]]=i;
    }
    for(int i=1;i<=m;i++)cout<<tong[i]<<' ';
    return 0;
}
