#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans;
bool check(){
    for(int i=3;i<=n;i++){
        if((a[i-1]-a[i-2])!=(a[i]-a[i-1])) return false;
    }
    return true;
}
void solve(){
    int p=a[2]-a[1];
    int q=p;
    while(true){
        if(m>=q){
            m-=q;
            q+=p;
            ans++;
        }else{
            break;
        }
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    int t, ans1=0, b[500005];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(check()==true){
        solve();
    }else{
        for(int i=a[1];i<=a[n];i++){
            for(int k=1;k<=n;k++) b[k]=a[k];
            t=m;
            ans1=0;
            for(int j=n;j>=1;j--){
                if(b[j]<=i){
                    if(t>=(i-b[j])){
                        t=t-(i-b[j]);
                        b[j]=i;
                        ans1++;
                    }
                }
            }
            ans=max(ans, ans1);
        }
        cout<<ans;
    }
    return 0;
}
