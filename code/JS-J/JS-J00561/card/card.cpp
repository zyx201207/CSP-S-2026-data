#include<bits/stdc++.h>
using namespace std;
int n,m,zz,q[9191991],qer[9191991],ans[9191991];
queue<int> pz;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>q[i];
    }
    for(int t=1;t<=n;t++){
        for(int i=t;i<=n;i++){
            if(qer[q[i]]==0){
                pz.push(q[i]);
                qer[q[i]]=1;
            }
            else if(qer[q[i]]==1){
                while(pz.size()){
                    qer[pz.front()]=0;
                    pz.pop();
                }
                pz.push(q[i]);
                qer[q[i]]=1;
            }
        }
        for(int i=0;i<=n;i++){
            qer[i]=0;
        }
        while(pz.size()){
            ans[pz.front()]++;
            pz.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
