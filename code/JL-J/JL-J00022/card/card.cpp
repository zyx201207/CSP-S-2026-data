#include<bits/stdc++.h>
using namespace std;
int n;
int a[500010],b[200010];
map<int,bool> b1;
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b1.clear();
        for(int j=i;j<=n;j++){
            if(b1.find(a[j])==b1.end()){
                b1[a[j]]=1;
                q.push(a[j]);
            }
            else{
                while(!q.empty()){
                    if(q.front()==a[j]){
                        break;
                    }
                    b1.erase(q.front());
                    q.pop();
                }
            }
        }
        for(auto j:b1){
            b[b1.first]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
