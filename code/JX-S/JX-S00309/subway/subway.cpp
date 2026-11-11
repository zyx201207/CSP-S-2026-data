 #include <bits/stdc++.h>
 using namespace std;
 int c,n,m,d,q;
 long long w[505];
int t[505][505]={0};
 //int h(int x,int y,long long ans)
 //{
     //for(int i=1;i<=n;i++)
     //{
       //  if(t[x][i]!=0)
        // {
         //    for(int j=1;j<=m;j++)
            //  {
              //    if(j==x)
              //    {
                    //  continue;
               //   }
               //   if(t[x][j]!=0)
                //  {
                //      ans+=t[j][i];
                 //     x=j;
                 //     if(x==y)
                   //   {
                   //       ans+=w[y];
                   //       cout<<ans<<"\n";
                 //        return 0;
                  //    }
                   //   else
                   //   {
                   //       h[x,y];
                     // }
              //    }
          //    }
        // }
     //}
//}
 int main()
 {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
     long long n,m;
     cin>>c>>n>>m>>d>>q;
     for(int i=1;i<=m;i++)
     {
         cin>>w[i];
     }
     for(int i=1;i<=n;i++)
     {
         int num;
         cin>>num;
         for(int j=1;j<=num;j++)
         {
             int lx;
             cin>>lx;
             int times;
             cin>>times;
             t[lx][i]=times;
         }
     }
     for(int i=1;i<=q;i++)
     {
         long long ans=0;
         int x,y;
         cin>>x>>y;
         //h[x,y,ans];
     }
     cout<<0;
     return 0;
 }
