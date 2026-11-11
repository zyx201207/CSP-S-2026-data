#include<bits/stdc++.h>
using namespace std;
stack<int> a;
queue<int> q;
int m,n,h[200],x,s[200];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        s[i]=x;
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            q.pop();
        }
        for(int j=1;j<=n-i+1;j++){
            if(h[q.front()]==1){
                while(a.top()!=q.front()){
                    a.pop();
                }
                a.pop();
                a.push(q.front());
                q.pop();
            }else{
                a.push(q.front());
                h[q.front()]=1;
            }
        }
        int sum=0;
        while(!a.empty()){
            sum++;
            a.pop();
        }
        cout<<sum<<" ";

    }
    return 0;
}

