#include<bits/stdc++.h>
using namespace std;
int a[5001];
long long b[300001];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;++i)
{
cin>>a[i];
}
long long sum1=0,sum2=0;
for(int i=1;i<=n;++i)
{
    if((a[i]==1&&a[n]==2)||(a[i]==2&&a[n]==1))
    {
        sum1++,sum2++;
    }
    if(a[i]==a[n])

    {
        if(a[i]==1)
            sum1++;
        else
            sum2++;
    }
}
cout<<sum1<<" "<<sum2<<endl;
return 0;
}
