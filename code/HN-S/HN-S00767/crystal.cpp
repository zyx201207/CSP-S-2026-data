#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int s[MAXN],a[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);int rs=0;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,num=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) num=mid,r=mid-1;
            else l=mid+1;
        }rs=max(rs,i-num+1);
    }cout<<rs;
    return 0;
}