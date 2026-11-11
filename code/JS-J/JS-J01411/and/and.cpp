#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    int ans=a[1]&a[2];
    for(int i=3;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
