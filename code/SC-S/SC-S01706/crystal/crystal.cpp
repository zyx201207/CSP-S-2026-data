#include<bits/stdc++.h>
const int N=5e5+11;
using namespace std;
int n;
long long m;
long long a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0;
    int l=1;
    int ans=0;
    for(int i=1;i <= n;i++){
        while(sum>m){
            sum-=a[i]-a[l++];
        }
        ans=max(ans,i-l+1);
        sum+=1ll*(i-l+1)*(a[i+1]-a[i]);
    }
    cout<<ans;
    return 0;
}