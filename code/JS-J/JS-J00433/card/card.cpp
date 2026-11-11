#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501];
int st[501];
int ans[201];
bool f[201];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
        f[j]=false;
       int top=0;
       for(int j=1;j<=n;j++)
        st[j]=0;
       for(int j=i;j<=n;j++)
       {
           if(!f[a[j]])
           {
               st[++top]=a[j];
               f[a[j]]=true;
           }
           else
           {
               int h;
               for(int k=1;k<=top;k++)
               {
                   if(st[k]==a[j])
                   {
                       h=k;
                       break;
                   }
               }
               while(top>h)
               {
                   f[st[top]]=false;
                   st[top]=0;
                   top--;
               }
           }
       }
       for(int j=1;j<=top+1;j++)
        ans[st[j]]++;
   }
   for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";
    return 0;
}
