#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+99999999;
ll n,a[N],ans;
char x;
string str;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x;
        for(int j=0;j<a[i];j++)
            str+=x;
    }
    for(int i=0,j=str.size()-1;i<=j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            str[j]=str[i];
            ans++;
        }
        else
            continue;
    }
    cout<<ans;
    return 0;
}
