#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000007]={0};
int b[1000007]={0};
int t[1000007]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> s;
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]==1){
                while(s.top()!=a[j]){
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
            }else{
                s.push(a[j]);
                t[a[j]]=1;
            }
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
