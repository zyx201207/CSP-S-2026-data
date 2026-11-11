#include<bits/stdc++.h>
using namespace std;
int a[200005],st[200005];
int n,m;
int _max=0;
void dfs(int e,int sum){
    if(e==0){
        _max=max(_max,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(st[i]||e<0)continue;
        st[i]=1;
        cout<<sum<<" ";
        sum&=a[i];
        dfs(e-1,sum);
        st[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    m--;
    for(int i=0;i<n;i++){
        st[i]=1;
        dfs(m,a[i]);
    }
    cout<<_max;
}
