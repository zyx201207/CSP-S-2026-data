#include<bits/stsdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int m string inn;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>inn;
        for(int j=1;j<=m;j++)
        {
            s+=inn;
        }
    }
    int sum=0;
    for(int i=0;i<s.size()*1.0/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
            `sum++;
    }
    cout<<sum;
    return 0;
}
