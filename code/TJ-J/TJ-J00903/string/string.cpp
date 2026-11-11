#include<bits/stdc++.h>
using namespace std;
int n,a;
long long l,sum;
char c;
string s=" ";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);//baoli
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        l+=a;
        for(int j=0;j<a;j++)
        {
            s=s+c;
        }
    }
    for(int i=1;i<=l/2+1;i++)
    {
        if(s[i]!=s[l-i+1])
        {
            s[i]=s[l-i+1];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
