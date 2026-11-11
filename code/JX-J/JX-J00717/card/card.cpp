#include<bits/stdc++.h>
using namespace std;
stack<int> v;
int n,m,a[500050],h[300030];
bool t[300030];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        while(!v.empty()){
            v.pop();
        }
        for(int i=j;i<=n;i++){
            if(a[i]==1){
                while(v.top()!=a[i]){
                    v.pop();
                }
            }
            v.push(a[i]);
            t[a[i]]=1;
        }
        for(int i=0;i<v.size();i++){
            h[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<h[i]<<" ";
    }
    return 0;
}
