#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[5005];
int n;
ll d;
bool check(int l,int r,ll d){
    if(a[r]-a[l]>=d) return 0;
    return 1;
}
void solve1(){
    int cnt=0;
    cin>>n>>d;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
            if(check(i,j)) cnt++;
        }
    }
    cout<<cnt<<endl;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) solve1();
    return 0;
}
