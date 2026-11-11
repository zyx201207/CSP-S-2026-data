#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
struct node{
    int x,nex;
}s[500005];
int main(){
  //  freopen("card.in","r",stdin);
  //  freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],q[a[i]].push(i);
    for(int i=1;i<=m;i++){
        while(!q[a[i]].empty()){
            int x=q[a[i]].front();
            q[a[i]].pop();
            s[x]={i,q[a[i]].front()};
        }
    }
    for(int i=1;i<=n;i++){
        int x=i;
        while(x<=n){
            while(q[a[x]].front()<i)q[a[x]].pop();
            b[a[x]]++;
            x=q[a[x]].front()-1;
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
