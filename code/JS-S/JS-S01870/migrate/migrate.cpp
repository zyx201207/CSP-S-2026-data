#include<bits/stdc++.h>
using namespace std;
int n;long long d;
long long a[2000005];
int solve(){
    cin>>n>>d;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int l = 1,r = 1;
    int ans = 0;
    while(l<=r&&r<n){
        if(abs(a[r]-a[r+1])>d){
            ans++;l=r+1,r++;
        }
        else{
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}
