#include<bits/stdc++.h>
using namespace std;
int a[500005],ans=-1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int op=m,cnt=1;
        for(int j=i-1;j>=1;j--){
            op-=a[i]-a[j];
            if(op>=0){
                cnt++;
                if(op==0) break;
            }
            else break;
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
