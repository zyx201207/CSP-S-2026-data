#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long ans=0;
string s;
struct node{
    int a;
    char c;
};
node a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].c;
        for(int j=1;j<=a[i].a;j++)
        {
            s+=a[i].c;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
