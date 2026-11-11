#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N],incnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
