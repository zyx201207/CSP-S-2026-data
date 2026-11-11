#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n,m,mn=1e9;
int a[N],d[N];
int init()
{
    int f=1,k=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    __int128 lst=0,k=0,l=1;
    int ans=0,res=0;
    for(int i=1;i<=n;i++){
//        cout<<i<<" "<<res<<" "<<ans<<'\n';
        k+=((i-1-l)*d[i]);
        lst+=d[i];
        ans=max(ans,res);
        if(k<=m){
            res++;
        }
        else{
            while(k>m){
                k-=lst;
                res--;
                lst-=d[l++];
            }
            res++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
