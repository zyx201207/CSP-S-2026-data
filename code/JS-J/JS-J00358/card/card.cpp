#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long f[305000],f2[300090];
queue<long long>p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>num;
        p.push(num);
    }
    memset(f,0,sizeof f);
    memset(f2,0,sizeof f2);
    for(long long i=1;i<=n;i++){
        stack<long long>q;
        for(long long j=0;j<i-1;j++){
            p.push(p.front());
            p.pop();
        }
        for(long long j=1;j<=n-i+1;j++){
            if(f2[p.front()]!=0){
                while(1){
                    if(q.top()==p.front())break;
                    q.pop();
                }
                p.push(p.front());
                p.pop();
                continue;
            }
            f2[p.front()]=1;
            q.push(p.front());
            p.push(p.front());
            p.pop();
        }
        while(!q.empty()){
            f[q.top()]++;
            q.pop();
        }
    }
    for(long long i=1;i<=m;i++)
        cout<<f[i]<<" ";
    return 0;
}
