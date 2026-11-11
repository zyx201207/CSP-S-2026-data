#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string a[200005];
    int b[200005];
    for(int i=1;i<=n;i++)
        {
            cin>>b[i]>>a[i];
        }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b[i];j++)
                {
                    s+=a[i];
                }
        }
    int len=s.size()-1;
    int ans=0;
    for(int i=0;i<=(len+1)/2;i++)
        {
            if(s[i]!=s[len-i])
                {
                ans++;
                }
        }
    cout<<ans;
    return 0;
}
