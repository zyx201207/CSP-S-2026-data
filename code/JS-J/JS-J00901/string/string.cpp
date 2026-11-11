#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0,x;
    char y;
    cin>>n;
    vector<char> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        while(x>0)
        {
            v.push_back(y);
            x--;
        }
    }
    for(int i=0,j=v.size()-1;i<=j;i++,j--)
    {
        if(v[i]!=v[j]) ans++;
    }
    cout<<ans;
    return 0;
}
