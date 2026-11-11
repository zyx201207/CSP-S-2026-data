#include<bits/stdc++.h>
using namespace std;
long long n,i,m,b;
char a;
string L,X;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        cin>>i>>a;
        for(int e=1;e<=i;e++)
        {
            L+=a;
            m++;
        }
    }
    for(int j=m-1;j>=0;j--)
    {
        X+=L[j];
    }
    for(int j=0;j<=m/2-1;j++)
    {
        if(X[j]!=L[j])
        {
            b++;
        }
    }
    cout<<b;





    return 0;
}
