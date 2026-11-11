#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1;
    long long cur=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cur+=(i-l)*(a[i]-a[i-1]);
        while(cur>m){
            cur-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
