#include<bits/stdc++.h>
using namespace std;
long long sum1[300002],cnt[300002];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cnt[i-1];
    }
    cout<<n;
    return 0;
}
