#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],ans[300005];
bool f=true;
stack<int>stk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) f=false;
    }
    if(f){
        for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) cout<<i<<" ";
        return 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=m;i++) p[i]=0;
        for(int i=k;i<=n;i++){
            if(p[a[i]]==0){
                stk.push(a[i]);
                p[a[i]]=stk.size();
            }
            else{
                while(stk.size()!=p[a[i]]){
                    p[stk.top()]=0;
                    stk.pop();
                }
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}