#include <bits/stdc++.h>
using namespace std;
int n,t,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a;
    string b="";
    int sum=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>a;
        for(int i=sum;i<=sum+n-1;i++)
        {
            b[i]=a;
        }
        sum+=n;
    }
    int changdu=sum-1;
    for(int i=0;i<=changdu/2;i++)
    {
        int f=changdu-i;

        if(b[i]!=b[f])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
