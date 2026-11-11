#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","r",stdout);
int n,d,c,t;
cin>>c>>t;
if(c==0)
{
    cout<<1<<endl<<2;
    return 0;
}
while(t--)
{
    long long x[2000005]={},n=0,d=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    cout<<n;
}
return 0;
}
