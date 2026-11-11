#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int c[500010];
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[200010]={};
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(s.top()!=a[j]){
                    b[s.top()]=0;
                    c[s.top()]--;
                    s.pop();
                }
            }
            else{
                s.push(a[j]);
                b[a[j]]++;
                c[a[j]]++;
            }
        }
        while(!s.empty()){
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
}
