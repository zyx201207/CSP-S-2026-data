#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int numm[300005];
int ans[300005];
stack <int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    int T=n;
    while(T--){
        memset(numm,0,sizeof(numm));
        while(!q.empty())
            q.pop();
        for(int j=i;j<=n;j++){
            if(numm[a[j]]==0){
                q.push(a[j]);
                numm[a[j]]=1;
            }
            else{
                while(q.top()!=a[j]&&!q.empty()){
                    numm[q.top()]=0;
                    q.pop();
                }
            }
        }
        for(int k=1;k<=m;k++){
            if(numm[k]==1){
                ans[k]++;
            }
        }
        i++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
