#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{int a;char s;
}z[200005];
stack<node> st1,st2;
signed main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n,cnt=0;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>z[i].a>>z[i].s;
       cnt+=z[i].a;
   }
   int r=cnt;
   int cnt6=cnt;
   if(cnt%2==1)
   {
       cnt6=cnt+1;
       cnt-=1;
   }cnt6/=2;
   cnt/=2;
   int l=0;
   for(int i=0;i<n;i++)
   {
       l+=z[i].a;
       if(l<cnt)
       {
           st1.push({z[i].a,z[i].s});
       }
       if(l>=cnt)
       {
           st1.push({z[i].a-abs(l-cnt),z[i].s});//cout<<z[i].a-abs(l-cnt)<<z[i].s;
           break;
       }
   }
   for(int i=n-1;i>=0;i--)
   {
       r-=z[i].a;
       if(r>cnt6)
       {
            st2.push({z[i].a,z[i].s});
       }
       if(r<=cnt6)
       {
            st2.push({z[i].a-abs(r-cnt6),z[i].s});//cout<<z[i].a-abs(r-cnt6)<<z[i].s;
           break;
       }
   }
   int ans=0;
   while(!st1.empty())
   {
       node temp1=st1.top();
       node temp2=st2.top();
      // cout<<temp1.a<<" "<<temp1.s;
      //  cout<<temp2.a<<" "<<temp2.s;
        st1.pop();
        st2.pop();
       if(temp1.a>temp2.a)
       {
           if(temp1.s!=temp2.s)
           ans+=temp2.a;
           st1.push({temp1.a-temp2.a,temp1.s});
       }
       if(temp1.a<temp2.a)
       {
           if(temp1.s!=temp2.s)
           ans+=temp1.a;
           st2.push({temp2.a-temp1.a,temp2.s});
       }
       if(temp1.a==temp2.a)
       {//cout<<temp1.s<<" "<<temp2.s;
           if(temp1.s!=temp2.s)
           ans+=temp1.a;
          // cout<<1;
       }
   }
   cout<<ans;
   }
