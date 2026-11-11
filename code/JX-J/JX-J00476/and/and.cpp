#include<iostream>
#include<string>
using namespace std;
#define endl '\n'
#define ll long long
int maxn=0;
    int a[200005];
    int n,m;
void solve(int x,int k,int ans){
    if(x==m+1){
        maxn=max(maxn,ans);
        return;
    }
    for(int i=k;i<=n;i++){
        if(x==m){
            maxn=max(maxn,ans&a[i]);
            return;
        }
        if(k==1)solve(2,i+1,a[i]);

        else solve(x+1,i+1,ans&a[i]);
    }
}
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve(1,1,0);
    cout<<maxn;
    return 0;
}
