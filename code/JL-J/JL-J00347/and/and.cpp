#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
long long n,m,a[N];
bool cmp(long long x,long long y){
    return x>y;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    if(m==1){
        cout<<ans;
        return 0;
    }
    else if(m==2){
        ans=ans&a[2];
        cout<<ans;
        return 0;
    }
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
