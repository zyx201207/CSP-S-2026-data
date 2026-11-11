#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N],cha[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cha[i]=a[i]-a[i-1];
    }
    sort(a+1,a+1+n);
    int maxn=-1;
    for(int i=2;i<=n;i++){
        int f=m;
        int ans=1;
        int j=i-1;
        while(j){
            if(a[i]-a[j]<=f/2) f-=a[i]-a[j],ans++;
            else{
                if(a[i]-a[j]<=f) ans++;
                break;
            }
            j--;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
