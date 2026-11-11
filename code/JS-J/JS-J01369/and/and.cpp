#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y){return x>y;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans<<"\n";
    return 0;
}