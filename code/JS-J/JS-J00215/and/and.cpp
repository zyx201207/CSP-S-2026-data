#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
int n,m;
ll maxa=-1;
void dfs(ll d,ll s,ll c){
    if(c==m){
        maxa=max(maxa,s);
        return ;
    }
    if(c==0){
        dfs(d+1,a[d],c+1);
    }
    dfs(d+1,s&a[d+1],c+1);
    if(n-d+1>m) dfs(d+1,s,c);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    ll ma=-1,an;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            an=a[i];
        }
        ma=max(ma,a[i]);
        an&=a[i];
    }
    if(m==1&&n<=2000){
        cout<<ma<<endl;
        return 0;
    }else if(n<=20){
        dfs(1,0,0);
        cout<<maxa<<endl;
        return 0;
    }else if(m==n&&n<=2000){
        cout<<an<<endl;
        return 0;
    }else if(m==2&&n<=2000){
        dfs(1,0,0);
        cout<<maxa<<endl;
        return 0;
    }else if(m==n-1&&n<=2000){
        dfs(1,0,0);
        cout<<maxa<<endl;
        return 0;
    }else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
        return 0;
    }
    return 0;
}
