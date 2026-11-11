#include<bits/stdc++.h>
using namespace std;
int a[200010],x[200010];
bool f[200010];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        stack<int>q;
        memset(f,0,sizeof f);
        for(int j=1;j<=i;j++){
            if(!f[j])q.push(j),f[j]=1;
            else {
                while(q.top()!=j)f[q.top()]=0,q.pop();
            }
        }
        while(!q.empty()){
            x[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<x[i]<<' ';
    return 0;
}
