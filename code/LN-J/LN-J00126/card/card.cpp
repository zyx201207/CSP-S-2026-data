#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int n,m,sum;
int a[maxx];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int g;
        cin>>g;
        a[g]++;
    }
    for(int i=1;i<=m;i++){
        cout<<sum+a[i]<<" ";
        sum+=a[i];
    }
    return 0;
}
