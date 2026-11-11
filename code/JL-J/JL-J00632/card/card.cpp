#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,a[1000000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<n<<m<<a[0];
    return 0;
}
