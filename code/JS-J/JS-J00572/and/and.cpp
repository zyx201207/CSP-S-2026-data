#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxn,a[N];
void dfs(int k,int last,int b){
    if(k==m){
        maxn=max(maxn,b);
        return;
    }
    int c;
    for(int i=last+1;i<=n;i++){
        c=b;
        c=c&a[i];
        if(c>maxn)dfs(k+1,i,c);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=2000){
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        cout<<a[m];
    }
    for(int i=1;i<=n;i++){
        dfs(1,i,a[i]);
    }
    cout<<maxn;
    return 0;
}
