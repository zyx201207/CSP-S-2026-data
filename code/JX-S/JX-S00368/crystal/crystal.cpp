#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+9;
long long n,m,sum,cnt,ans;
long long arr[N],diff[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){diff[i]=arr[i]-arr[i-1];}
    for(int i=2;i<=n+1;i++){
        sum+=(diff[i]*(++cnt));
        ans++;
        if(sum>m){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
