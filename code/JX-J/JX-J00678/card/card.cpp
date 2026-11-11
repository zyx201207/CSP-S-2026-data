#include <iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k[500010];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>k[i];
    for(int i=1;i<n+1;i++)
        cout<<i<<" ";
}
