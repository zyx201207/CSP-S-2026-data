 #include <bits/stdc++.h>
 using namespace std;
 int n,m;
 int a[500005];
 bool f[500020];
 int b[500020];
 int c[500020];
 int u[500020];
 int main()
 {
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&a[i]);
     }

     for(int i=1;i<=n;i++)
     {
         memset(f,0,sizeof(f));
         memset(u,0,sizeof(u));
         for(int j=i;j<=n;j++)
         {
             int w=0;
             if(f[a[j]]==1)
             {
                for(int e=i;e<j;e++)
                {
                    if(a[e]==a[j]&&u[e]==0)
                    {
                        w=1;
                    }
                    if(w==1&&u[e]==0)
                    {
                        u[e]=1;
                        f[a[e]]=0;
                    }
                }
                f[a[j]]=1;
             }
             else
             {
                f[a[j]]=1;
             }

         }
         for(int j=i;j<=n;j++)
         {
             if(u[j]==0)
             {
                 b[a[j]]++;
             }

         }
     }
     for(int i=1;i<=m;i++)
     {
         printf("%d ",b[i]);
     }
     return 0;
 }
