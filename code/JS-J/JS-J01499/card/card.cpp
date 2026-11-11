#include<bits/stdc++.h>
using namespace std;
int n,m;
bool w=1;
int vis[500005],a[500005],b[500005];
queue<int>q;
queue<int>p;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]<b[i-1])w=0;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2||w==1){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                vis[i]=0;
            }
            for(int i=1;i<=n;i++){
                vis[b[i]]=1;
            }
            for(int i=1;i<=m;i++){
                if(vis[i]==1)a[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            q.push(b[i]);
        }
        while(!q.empty()){
            bool f=0;
            if(vis[q.front()]==0){
                p.push(q.front());
                vis[q.front()]=1;
                q.pop();
            }
            else{
                x=q.front();
                q.pop();
                while(1){
                    if(p.front()==x){
                        p.push(p.front());
                        p.pop();
                        while(p.front()!=x){
                            p.pop();
                        }
                        f=1;
                    }
                    else{
                        p.push(p.front());
                        p.pop();
                    }
                    if(f==1)break;
                }
            }
        }
        while(!p.empty()){
            a[p.front()]++;
            p.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
