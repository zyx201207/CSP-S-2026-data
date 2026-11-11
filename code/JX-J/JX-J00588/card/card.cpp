#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        queue<int> q;
        int cc[205]={};
        for(int j=i;j<=n;j++){
            cc[a[j]]++;
            if(cc[a[j]]>=2){
                bool v=0;
                cc[a[j]]--;
                while(q.size()){
                    int x=q.front();
                    if(x==a[j]){
                        v=1;
                    }
                    if(v){
                        q.pop();
                        cc[a[j]]--;
                        v=1;
                    }
                }
            }
            q.push(a[j]);
        }
        while(q.size()){
            int xx=q.front();
            q.pop();
            if(c[xx]!=i){
                c[xx]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
