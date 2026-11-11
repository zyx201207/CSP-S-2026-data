#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],s[5010];
queue <int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int k=1;k<=n;k++)cin>>a[k];
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            int u=0;
            queue <int> w;
            while(!q.empty()){
                w.push(q.front());
                if(q.front()==a[i])u=1;
                q.pop();
            }
            if(u==1){
                while(w.front()!=a[i]){
                    q.push(w.front());
                    w.pop();
                }
                while(!w.empty()){
                    w.pop();
                }
            }
            else{
                while(!w.empty()){
                    q.push(w.front());
                    w.pop();
                }
            }
            q.push(a[i]);
        }
        while(!q.empty()){
            s[q.front()]++;
            q.pop();
        }
    }
    for(int k=1;k<=m;k++)cout<<s[k]<<' ';
    return 0;
}
