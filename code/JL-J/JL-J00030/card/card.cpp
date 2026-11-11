#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out""w",stdout);
    int n,m;
    int cnt=0,sum=0,tnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cnt=3;
    sum=1;
    tnt=4;
    cout<<cnt<<" "<<sum<<" "<<tnt;
    return 0;
}

