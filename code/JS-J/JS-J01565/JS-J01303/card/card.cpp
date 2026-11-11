#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
short v[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=300005;j++) v[j]=0;
        stack<int> s;
        s.push(a[i]);
        v[a[i]]=1;
        for(int j=i;j<=n;j++){
            if(v[a[j]]==0){
                s.push(a[j]);
                v[a[j]]=1;
            }
            else{
                while(1){
                    if(s.top()!=a[j]){
                        v[s.top()]=0;
                        s.pop();
                    }
                    else break;
                }
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
