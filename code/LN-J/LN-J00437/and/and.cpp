#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,a[10000],b[10000],c,q=111111,maxx,bijiao=0,d[10000],sum=0,g;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         if(n==1){
            cout<<a[i];
            return 0;
         }

         g=a[i];
         for(int k=1;;k++)
         {
             if(pow(2,k)<=a[i]&&pow(2,k+1)>a[i])
                c=k;

         }
         for(int w=c;w>=0;w--)
         {

             b[w]=g%2;
             g/=2;
         }
     }
     if(m==n)
     {
         for(int i=1;i<=n;i++)
            cout<<a[i];
        return 0;
     }
     if(n==2)
     {
         cout<<max(a[1],a[2]);
         return 0;
     }
     for(int i=1;i<=m;i++)
     {
         for(int j=1;j<=n;j++)
         {
             maxx=q&&b[j];
            maxx=max(maxx,bijiao);

         }
        q=maxx;
     }
    for(int i=1;i<=6;i++)
    {
        d[i]=q%10;
        q/=10;

    }
    for(int i=1;i<=6;i++)
        sum+=d[i]*pow(2,i-1);


    cout<<sum;







    return 0;
}
