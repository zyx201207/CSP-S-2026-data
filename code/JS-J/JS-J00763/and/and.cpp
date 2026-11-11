#include <bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n>>m;
   priority_queue <int> a;
   for(int i=1;i<=n;i++){
        int q;
        cin>>q;
        a.push(q);
   }
   int ans;
   for(int i=1;i<=n;i++){
       if(i==m) ans=a.top();
       a.pop();
   }
   cout<<ans;
   return 0;
}
