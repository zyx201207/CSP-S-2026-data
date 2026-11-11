#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,ans=0;
struct node
{long long m;
 char ch;
}a[200005];
int main()
{freopen("string.in","r",stdin);
 freopen("string.out","w",stdout);
 //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
 cin>>n;
 for(int i=1;i<=n;i++)
  {cin>>a[i].m>>a[i].ch;
   cnt+=a[i].m;
  }
 for(int i=1;i<=n/2;)
 {long long j=n;
  if(a[i].ch!=a[j].ch){ans+=min(a[i].m,a[j].m);}
                       if(a[i].m>a[j].m){a[i].m-=a[j].m;j--;}
                         else if(a[i].m<a[j].m){a[j].m-=a[i].m;i++;}
                           else {i++;j--;}

 }
 cout<<ans;
    return 0;
}
