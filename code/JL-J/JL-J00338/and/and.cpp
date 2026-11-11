#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        cout<<"0\n";
        return 0;
    }
    int ans=0;
    for(int i=29;i>=0;i--){
        int tmp=(ans|(1<<i));
        int cnt=0;
        for(int j=1;j<=n;j++){
            if((a[j]&tmp)==tmp){
                cnt++;
            }
        }
        if(cnt>=m){
            ans|=(1<<i);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
