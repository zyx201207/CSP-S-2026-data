#include<bits/stdc++.h>
using namespace std;
int a,b,c[500000],sum1=0,sum2=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>c[i];
    }
    if(b==1)
    {
        cout<<a;
        return 0;
    }
    if(b==2)
    {
        for(int i=0;i<a;i++)
        {
            if(c[i]==1)
                sum1++;
            else
                sum2++;
        }
        cout<<sum1<<" "<<sum2;
    }
    return 0;
}
