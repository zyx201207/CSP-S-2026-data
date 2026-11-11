#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005],b[1000005];
bool vis[1000005];
int main()
{freopen("card.in","r",stdin);
 freopen("card.out","w",stdout);
 //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
 cin>>m>>n;
 for(int i=1;i<=m;i++)
   cin>>a[i];
 for(int i=1;i<=m;i++)
 {memset(vis,0,sizeof(vis));
  stack<int>s;
  for(int j=i;j<=m;j++)
   {if(vis[a[j]]==0)vis[a[j]]=1;
      else{while(a[j]==s.top())
           s.pop();
           s.pop();
      }
   }
   b[s.size()]++;
 }
 for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
    return 0;
}
