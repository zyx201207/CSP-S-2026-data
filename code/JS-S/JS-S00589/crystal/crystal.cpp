#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

const int N=5e5+3;

int n,m;
int a[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=1,sum=0;
    for(int l=1,r=2;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(sum>m){
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}