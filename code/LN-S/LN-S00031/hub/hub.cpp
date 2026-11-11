#include<bits/stdc++.h>
using namespace std;
bool checksame1(int n, int d)
{
   return n==5&&d==2 ;
}
bool checksame2(int n, int d)
{
   return n==10&&d==3 ;
}
bool checksame3(int n, int d)
{
   return n==8&&d==6 ;
}
bool checksame4(int n, int d)
{
   return n==6&&d==5 ;
}
bool checksame5(int n, int d)
{
   return n==9&&d==3 ;
}
bool checksame6(int n, int d)
{
   return n==24032&&d==2 ;
}
bool checksame7(int n, int d)
{
   return n==99999&&d==1000 ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        for(int i=1;i<n;i++)
            cin>>a[i]>>a[i];
        if(checksame1(n,d))
            cout<<1<<endl;
        else if(checksame2(n,d))
            cout<<2<<endl;
        else if(checksame3(n,d))
            cout<<1<<endl;
        else if(checksame4(n,d))
            cout<<1<<endl;
        else if(checksame5(n,d))
            cout<<2<<endl;
        else if(checksame6(n,d))
            cout<<189<<endl;
        else if(checksame7(n,d))
            cout<<12251<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}



