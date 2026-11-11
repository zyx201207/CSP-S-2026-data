#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],s[N],res;
void init(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
bool check(int i,int k){
    int t=m-(a[i]*(i-k+1)-s[i]+s[k-1]);
    return t>=0;
}
signed main(){
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(i,mid)) r=mid-1;
            else l=mid+1;
        }
        res=max(res,i-l+1);
    }
    cout<<res<<"\n";
    return 0;
}
