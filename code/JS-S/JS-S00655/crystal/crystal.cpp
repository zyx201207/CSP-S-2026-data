#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
using namespace std;
long long n,m,a[500005];
deque<long long>q;
int ans=1;
inline long long read()
{
    long long x=0,f=1;
    char ch=gc();
    while(!isdigit(ch)&&ch!='-')ch=gc();
    if(ch=='-')
    {
        f=-1;
        ch=gc();
    }
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
inline void print(int x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(x<10)
    {
        pc(x^48);
        return;
    }
    print(x/10);
    pc(x%10^48);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   cin>>n;
   if(n<=5000)
   {
       cin>>m;
       for(int i=1;i<=n;++i)cin>>a[i];
       sort(a+1,a+1+n);
       int numqian=1;
       q.push_back(a[1]);
       for(int i=2;i<=n;++i)
       {
           if(a[i]==a[i-1])
           {
               q.push_back(a[i]);
               numqian++;
               ans=max(ans,numqian);
               continue;
           }
           long long cha=a[i]-a[i-1];
           while(numqian*cha>m&&numqian)
           {
               numqian--;
               m=m+(a[i-1]-q.front());
               q.pop_front();
           }
           q.push_back(a[i]);
           m=m-(numqian*cha);
           numqian++;
           ans=max(ans,numqian);
       }
       cout<<ans;
       return 0;
    }
   m=read();
   for(int i=1;i<=n;++i)a[i]=read();
   sort(a+1,a+1+n);
   int numqian=1;
   q.push_back(a[1]);
   for(int i=2;i<=n;++i)
   {
       if(a[i]==a[i-1])
       {
           q.push_back(a[i]);
           numqian++;
           ans=max(ans,numqian);
           continue;
       }
       long long cha=a[i]-a[i-1];
       while(numqian*cha>m&&numqian)
       {
           numqian--;
           m=m+(a[i-1]-q.front());
           q.pop_front();
       }
       q.push_back(a[i]);
       m=m-(numqian*cha);
       numqian++;
       ans=max(ans,numqian);
   }
   cout<<ans;
   return 0;
}
