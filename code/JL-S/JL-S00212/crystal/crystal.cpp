

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,s[N],ans=1,b=0,c=0;
bool cmp(int x,int y){
    return x<y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int k=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=a[i+1]-a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(s[i]<k){
            k-=(s[i]*i);
            a[i]=a[i+1];
            s[i]=a[i+2]-a[i+1];
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}

