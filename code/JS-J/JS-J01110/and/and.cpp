#include<bits/stdc++.h>
using namespace std;
#define intt long long
const int MAXN=200005;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=(1<<31)-1;
    cin>>n>>m;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=0;
        int g=a[i].first;
        while(g)
        {
            a[i].second+=g%2;
            g/=2;
        }
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<m;i++) ans=(ans&a[i].first);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
