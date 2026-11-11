#include <bits/stdc++.h>
using namespace std;
int er[10000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i = 0;i<a;i++){
        cin>>er[i];
    }
    int ans=0;
    for(int i = 0;i<a;i++){
        ans=max(ans,er[i]);
    }
    cout<<ans;
}
