#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,ans,num,wum;
char b;
char c[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a>>b;
        wum+=a;
        for(int j=1;j<=a;j++)
        {
            num++;
            c[num]=b;
        }
    }
    for(int i=1;i<=num/2;i++)
    {
        if(c[i]==c[num+1-i])
        {
            continue;
        }
        else{
            sum++;
        }
    }
    cout<<sum;
}
