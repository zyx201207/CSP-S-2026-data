#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,a[N],b1,b2;
bool vis[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    if(m == 1) cout << 1;
    return 0;
}
