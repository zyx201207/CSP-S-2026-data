#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll m;

const int N=5e5+10;
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1;
    int ans=0;ll sum=0;
    for(int r=1;r<=n;r++){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m){
            sum-=a[r]-a[l];l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
/*
5 8
 -3 -1 2 2 7
*/
