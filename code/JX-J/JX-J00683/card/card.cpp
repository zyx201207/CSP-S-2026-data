#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool had[300005];
int ans[300005];
stack<int> s;
void gl(){
    for(int i=1;i<=m;i++)
        had[i]=0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1;
    while(l<n){
        gl();
        while(!s.empty()) s.pop();
        for(int i=l;i<=n;i++){
            if(!had[a[i]]){
                had[a[i]]=1;
                s.push(a[i]);
            } else{
                while(!s.empty()){
                    int x=s.top();
                    if(x==a[i])  break;
                    else{
                        s.pop();
                        had[x]=0;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++) ans[i]+=had[i];
        l++;
    }
    ans[a[n]]++;
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
