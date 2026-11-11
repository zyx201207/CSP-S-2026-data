#include <bits/stdc++.h>
using namespace std;
int a[300005]={0},b[300005]={0},c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    stack<int> p;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++){
        for(int j=0+i;j<n;j++){
            if(b[c[j]]==1){
                while(p.top()!=c[j]){
                    b[p.top()]=0;
                    p.pop();
                }
                p.pop();
            }
            p.push(c[j]);
            b[c[j]]=1;
        }
        while(!p.empty()){
            a[p.top()]+=1;
            p.pop();
        }
        for(int z=1;z<=m;z++)b[z]=0;
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<' ';
    }
}
