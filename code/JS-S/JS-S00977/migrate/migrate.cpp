#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int a,s;
cin>>a>>s;
for(int i=0;i<s;i++)
{
    int temp1,temp2,temp3,temp4;
cin>>temp1>>temp2;
cin>>temp3>>temp4;
temp4-=temp3;
int ans=0;
for(int j=1;j<=temp4;j++)
{
    ans+=(temp1-(temp2+j));
}
for(int j=2;j<temp1;j++)
{
    int temp;
    cin>>temp;
}cout<<ans<<endl;
}
}
