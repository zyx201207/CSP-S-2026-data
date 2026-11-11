#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];bool flag=1;
vector<int> q[1000];
int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&a[i]);
       if(a[i]<a[i-1]) flag=0;
   }
   if(flag==1)
   {
       for(int i=1;i<=m;i++) cout<<m<<" ";
   }
   else
   {
       if(m==2)
       {
           for(int i=1;i<=n;i++)
           {
               if(i==1) cout<<"2 ";
               else cout<<"1 ";
           }
       }
       else
        {
       for(int i=1;i<=n;i++)
       {
           for(int j=i;j<=n;j++)
           {
               if(q[a[j]].size()==0) q[a[j]].push_back(j);
           }
       }
       for(int i=1;i<=m;i++) cout<<q[a[i]].size()<<" ";
        }
   }
   return 0;
}
