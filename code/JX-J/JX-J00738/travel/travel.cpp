#include<bits/stdc++.h>
using namespace std;
int x[20],a[100][100],y[20],b[100][100],m,n,g,h;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>m;
    for(int i=1;i<=17;i++)
    {
       cin>>x[i];
       for(int i=1;i<=17;i++)
       {
           cin>>y[i];
           if(x[i]==y[i]) m=="1";
           else m=="0";
       }
    }
    string s;
    cin>>s;
    cin>>n>>g>>h;
    for(int i=1;i<=18;i++)
    {
       for(int j=1;j<=s.size;j++)
       cin>>a[i][j];
       for(int i=1;i<=18;i++)
       {
           for(int j=1;j<=s.size();j++)
           cin>>b[i][j];
           if(a[i]==b[i]) n=="1";
           else n=="0";
           if(a[i]==b[i]&&a[j]=="A"&&b[j]=="B") g=="1";h=="1";
           if(a[i]==b[i]&&a[j]=="A"&&b[j]=="C") g=="1";h=="0";
           if(a[i]==b[i]&&a[j]=="B"&&b[j]=="C") g=="1";h=="1";
           if(a[i]==b[i]&&b[j]=="A"&&a[j]=="B") g=="1";h=="1";
           if(a[i]==b[i]&&b[j]=="A"&&a[j]=="C") g=="1";h=="0";
           if(a[i]==b[i]&&b[j]=="B"&&a[j]=="C") g=="1";h=="1";
           if(a[i]==b[i]&&a[j]=="D"&&b[j]=="F") g=="1";h=="1";
           if(a[i]==b[i]&&a[j]=="F"&&b[j]=="D") g=="1";h=="1";
           else g=="0";h=="0";
       }
    }
    cout<<m<<n<<g<<h;
    return 0;
}
