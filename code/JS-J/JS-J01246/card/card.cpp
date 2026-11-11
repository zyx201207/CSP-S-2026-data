#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],h[300001],sum[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=500){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) h[j]=0;
            stack<int> q;
            for(int j=i;j<=n;j++){
                if(h[a[j]]==0){
                    q.push(a[j]);
                    h[a[j]]++;
                }
                else{
                    while(!q.empty()&&q.top()!=a[j]){
                        h[q.top()]--;
                        q.pop();
                    }
                }
            }
            for(int j=1;j<=m;j++){
                if(h[j]!=0) sum[j]++;
            }
        }
        for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
    }
    else{
        for(int i=1;i<=n;i++) h[a[i]]=i;
        for(int i=1;i<=m;i++) cout<<h[i]<<' ';
    }
    return 0;
}
