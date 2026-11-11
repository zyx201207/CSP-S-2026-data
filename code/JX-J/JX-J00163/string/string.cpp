#include<bits/stdc++.h>
using namespace std;
long long n,l,cnt;
string xin;
void huiwen()
{
    for(int i=0;i<ceil(l*1.0/2);i++)
    {
        if(xin[l-i-1]!=xin[i])
        {
            cnt++;
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        int a;
        char s1;
        cin>>a>>s1;
        for(int i=1;i<=a;i++)
        {
            xin[l]=s1;
            l++;
        }
    }
    huiwen();
    cout<<cnt;
    return 0;
}
