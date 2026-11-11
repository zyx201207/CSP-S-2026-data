#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m; 
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=1;
    for(int i=n;i>0;i--){
        ll rem=m;
        int cnt=0;
        ll t=a[i];
        int j=i;
        while(rem>=0&&j>0){
            rem-=(t-a[j]);
            //cout<<j<<" ";
            j--;
            cnt++;
        }
        if(rem<0){
            cnt--;
        }
        //cout<<cnt<<" "<<rem<<"\n";
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
    
}
//贪心居然假了
//暴力过不了crystal4（这样显然最多拿45分）
//？好像可以过