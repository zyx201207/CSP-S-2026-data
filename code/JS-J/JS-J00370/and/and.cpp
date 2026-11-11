#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500011;
int n,m,a[N];
bool sol[20][N];
int od[300011];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1]<<"\n";
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<"\n";
    }else{
        int ans=a[1];
        for(int i=2;i<=m;i++) ans&=a[i];
        cout<<ans<<"\n";
    }
    return 0;
}
