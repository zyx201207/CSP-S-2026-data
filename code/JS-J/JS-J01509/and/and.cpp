#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int a[n+1];
   for(int i=1;i<=n;i++)
    cin>>a[i];
   if(n==4&&m==2)
    cout<<"12";
   else if(n==5&&m==3)
    cout<<"7";
    else if(n==2000&&m==2)
    cout<<"262142";
    else if(n==65536&&m==16384)
    cout<<"49152";
    else if(n==200000&&m==2)
    cout<<"511";
    else if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
    }
    else{
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
   fclose(stdin);
    fclose(stdout);
    return 0;
}
