#include<bits/stdc++.h>
using namespace std;
int a[505];
int x[205];
int vis[205];
int n, m;

queue<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

     cin >> n >> m;
     for(int i =1;i<=n;i++)
     {
         cin >> a[i];
     }
     while(m--)
     {
         for(int i =1;i<=n;i++)
         {
             if(x[a[i]] == 0)
             {
                 x[a[i]]++;
                 q.push(a[i]);
             }

             else break;
         }
         while(q.size() != 0)
         {
             vis[q.front()]++;
             q.pop();
         }
     }
     for(int i = 1;i<=m;i++)
     {
         if(vis[i] != 0)
            cout << vis[i];
     }


    return 0;
}
