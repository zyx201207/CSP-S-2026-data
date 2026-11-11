#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long int s,prefix[N],cnt;
struct node
{
    long long int a;
    char c;
};
struct node2
{
    long long int num;
    char c1;
};
node group[N];
int main()
{
   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>group[i].a>>group[i].c;
       s+=group[i].a;
       prefix[i]=prefix[i-1]+group[i].a;
   }
   //for(int i=1;i<=ceil(n/2.0);i++)
   node2 i,j;
   i.num=group[1].a,i.c1=group[1].c;
   j.num=group[n].a,j.c1=group[n].c;
   int l=1,r=n;
   while(l<r)
   {
      if(i.num<j.num)
      {
          if(i.c1!=j.c1)
          {
              cnt+=i.num;
          }
          j.num-=i.num;
          l++;
          i.num=group[l].a,i.c1=group[l].c;
      }
        if(i.num>j.num)
        {
          if(i.c1!=j.c1)
          {
              cnt+=j.num;
          }
          i.num-=j.num;
          r--;
          j.num=group[r].a,j.c1=group[r].c;
        }
       if(i.num==j.num)
        {
          if(i.c1!=j.c1)
          {
              cnt+=j.num;
          }
          l++;
          i.num=group[l].a,i.c1=group[l].c;
          r--;
          j.num=group[r].a,j.c1=group[r].c;
        }
   }
   cout<<cnt<<endl;
    return 0;
}






































