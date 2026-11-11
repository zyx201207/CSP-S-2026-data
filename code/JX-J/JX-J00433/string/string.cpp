#include<bits/stdc++.h>
using namespace std;
const int N=5*1e8+36867911;
int a[N],cnt=0;
string s="";
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>a[i]>>x;
        for(int j=1;j<=a[i];j++) s+=x;
    }
    string z=s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=z.size()-1;j>=0;j--)
        {
            if(z[j]!=s[i])
            {
                z[i]=s[j];
                cnt++;
            }
            i++;
        }

    }
    cout<<cnt;
    return 0;
}
