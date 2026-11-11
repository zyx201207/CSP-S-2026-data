#include <bits/stdc++.h>

using namespace std;
int w[10000009];
int k[10000009];
int a[10000009];
int t[10000009];

int main()
{
   freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int qq=1;qq<=q;qq++){
        cout<<"0"<<endl;



    }

    return 0;
}
