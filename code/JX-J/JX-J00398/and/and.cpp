#include<bits/stdc++.h>
using namespace std;
int main()
{

 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);

 int n,m;
 int num[1000005];
 int maxnum=0;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
     cin>>num[i];
 }
 for(int i=1;i<=n;i++)
 {
     if(num[i]>maxnum)
     {
         maxnum=num[i];
     }
 }
 cout<<maxnum;
 return 0;
}
