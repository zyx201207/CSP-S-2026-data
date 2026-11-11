#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[200001];
bool che(int i,int j){
    if(a[j]-a[i]<=d&&i-j==2){
        return 1;
    }
    if((a[j]-a[i])/d>i-j){
        return 0;
    }
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    int ans;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(che(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
