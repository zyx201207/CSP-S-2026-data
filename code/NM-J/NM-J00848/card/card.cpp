#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],b[300010];
void f(int x){
    if(x!=b[a[x]])f(b[a[x]]);
    else{
        ans[a[x]]++;
        if(x<n)f(x+1);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)f(i);
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
