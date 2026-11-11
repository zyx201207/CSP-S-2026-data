 #include <bits/stdc++.h>
 using namespace std;
 int n,m;
 int a[500030];
 int f[500030];
 int main()
 {
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
     scanf("%d%d",&n,&m);
     int maxx=0;
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&a[i]);
     }
     for(int i=1;i<=n;i++)
     {
         if(f[a[i]]==1)
         {
             maxx=max(maxx,a[i]);
         }
         else
         {
             f[a[i]]=1;
         }
     }
     printf("%d",maxx);
     return 0;
 }
