#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a;
    char c;
    char s[100001]={0};
    cin>>n;
    int text=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
            for(int i=text;i<=text+a;i++)
            {
                s[i]=c;
            }
            text+=a;
    }
    char com[100001]={0};
    for(int i=1;i<text;i++)
    {
        com[i]=s[text-i];
    }
    int sum=0;
    for(int i=1;i<text;i++)
    {
        if(s[i]!=com[i])
        {
            sum++;
        }
    }
    sum/=2;
    cout<<sum;
    return 0;

}
