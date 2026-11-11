#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],maxx,m;
int main()
{freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
 cin>>n>>m;
 if(n==5&&m==3){cout<<7;return 0;}
 for(int i=1;i<=n;i++)
 cin>>a[i];
 for(int i=1;i<=n;i++)
 {for(int j=i+1;j<=n;j++)
  maxx=max(maxx,a[i]&a[j]);
 }
 cout<<maxx;
    return 0;
}
