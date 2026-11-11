#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],ans[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int st=1;st<=n;st++){
        memset(p,0,sizeof(p));
        for(int i=st;i<=n;i++){
            if(p[a[i]]==1){
                while(s.top()!=a[i]){
                    p[s.top()]=0;
                    s.pop();
                }
            }
            else{
                s.push(a[i]);
                p[a[i]]=1;
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
