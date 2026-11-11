#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
bool c[200005];
stack<long long> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            if(c[a[j]]==1){
                while(!q.empty()&&q.top()!=a[j]){
                    c[q.top()]=0;
                    q.pop();
                }
                q.pop();
                c[a[j]]=0;
            }
            q.push(a[j]);
            c[a[j]]=1;
        }
        while(!q.empty()){
            b[q.top()]++;
            q.pop();
        }
    }
    cout<<1<<endl;
    b[a[n]]++;
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
