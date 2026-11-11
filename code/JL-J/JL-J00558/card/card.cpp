#include <bits/stdc++.h>
using namespace std;
vector<int> q;
int n,m,a[1000010],v[1000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        v[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
