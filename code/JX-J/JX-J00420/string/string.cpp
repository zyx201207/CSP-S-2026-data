#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a,lo=0;
    char c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        lo+=a;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    int min_=-1,k=0;
    for(int i=0,j=lo-1;i<lo/2;i++,j--)
    {
        if(s[i]!=s[j]) k++;
    }
    cout<<k;
    //cout<<s<<l;
    return 0;
}
