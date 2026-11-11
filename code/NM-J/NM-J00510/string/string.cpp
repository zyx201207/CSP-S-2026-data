#include<bits/stdc++.h>
using namespace std;
int a[100001];
char c[100001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
       for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s=s+c[i];
        }
    }
    if(s.size()%2==0)
    {

    }
    return 0;
}
