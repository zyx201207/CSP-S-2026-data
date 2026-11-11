#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[300005]={};
    queue<int> q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(a[300005]==0)q.push(k);
        else q.pop();
        for(int j=1;j<=m;j++)a[j]++;
    }
    for(int i=1;i<=m;i++)cout<<a[i]<<' ';
    return 0;
}
