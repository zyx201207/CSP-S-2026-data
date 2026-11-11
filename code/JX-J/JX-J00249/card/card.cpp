#include<bits/stdc++.h>
using namespace std;
int a[500009];
int ans[300009];

stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1;
    while(l<=n){
        bool f[300009]={0};
       for(int i=l;i<=n;i++){
             if(f[a[i]]==1){
            while(s.top()!=a[i]){
                    f[s.top()]=0;
                    s.pop();
                }
            }else s.push(a[i]);
            f[a[i]]=1;
       }
       for(int i=1;i<=m;i++){
            if(f[i]==1) ans[i]++;
       }
       l++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
return 0;
}
