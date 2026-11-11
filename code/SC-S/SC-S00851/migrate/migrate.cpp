#include <bits/stdc++.h>
using namespace std;

struct island{
    int pos,step,times,minstep,index;
};

int c,t;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        int cnt=0;
        island x[2000006]={};
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i].pos;
            x[i].index=i;
        }
        if(n<4 ||d==1){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n-3;i++){

            for(int j=i;j<=n;j++){
                x[j].step=0;
                x[j].times=1;
                x[j].minstep=1e9;
            }
            queue<island> q;
            q.push(x[i]);
            while(!q.empty()){
                island f=q.front();
                for(int j=f.index+1;j<=n;j++){
                    if(x[j].pos-f.pos>d) break;
                    x[j].step=f.step+1;
                    if(x[j].step<x[j].minstep){
                        x[j].times=0;
                        x[j].minstep=x[j].step;
                    }
                    if(x[j].step==x[j].minstep) x[j].times++;
                    q.push(x[j]);
                }
                q.pop();
            }
            for(int j=i+1;j<=n;j++){
                if(x[j].times==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}