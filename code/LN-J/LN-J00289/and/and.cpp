#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
