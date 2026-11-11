#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    int now=0,maxn=1;
    for(r=2;r<=n;r++){
        now+=(a[r]-a[r-1])*(r-l);
        while(now>m){
            now-=a[r]-a[l];
            l++;
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn<<endl;
    return 0;
}