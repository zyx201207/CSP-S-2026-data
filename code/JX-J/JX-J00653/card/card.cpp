#include <bits/stdc++.h>
using namespace std;
long long a[6666];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
long long m,n;
cin>>m>>n;
for(long long i=1;i<=n;i++)
{
    cin>>a[i];
}
for(long long i=1;i<=n;i++)
{

    cout<<a[i]<<" ";
}


return 0;}
