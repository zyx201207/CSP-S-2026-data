 #include<bits/stdc++.h>
 using namespace std;
long long mm[500005];
 long long na[505][505];
 long long nt[505][505];
 long long nq1[100000];
 long long nq2[100000];
 int main()
 {
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
     long long c,n,m,d,q;
     cin>>c>>n>>m>>d>>q;
     for(int i=1;i<=m;i++)
     {
         cin>>mm[i];
     }
     for(int i=1;i<=n;i++)
     {
         int ki;
         cin>>ki;
         int s=0;
         for(int j=1;j<=2*ki;j++)
         {
             cin>>na[i][j]>>nt[i][j];
         }
     }
     for(int i=1;i<=q;i++)
     {
         cin>>nq1[i]>>nq2[i];
     }
     for(int z=1;z<=q;z++)
     {
         int i1=0,i2=0,ss=0,summ=0;
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=505;j++)
             {
                 if(na[i][j]==nq1[z])
                 {
                     ss=1;
                     if(na[i+1][j]==0)
                     {
                         i1=na[i-1][j];
                         summ+=mm[na[i][j]]+nt[i][j];
                     }
                     else
                     {
                         i1=na[i+1][j];
                         summ+=mm[na[i][j]]+nt[i][j];
                     }
                 }
                 if(i1==nq2[z])
                 {
                     summ+=mm[na[i][j]]+nt[i][j];
                 }
             }
         }
         cout<<summ<<endl;
     }
     return 0;
 }
