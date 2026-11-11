#include<bits/stdc++.h>
using namespace std;
char ans[1000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char> v;
    int n,cnt=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        char c;
        cin>>c;
        for(int j=1;j<=a;j++)
        {
            v.push_back(c);
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        ans[i]=v[i];
    }
    for(int i=1;i<=cnt;i++)
    {
        if(ans[i]!=ans[cnt-i])
        {
            sum++;

        }
    }
    cout<<sum;
}
