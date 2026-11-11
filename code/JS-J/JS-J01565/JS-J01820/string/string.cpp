#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
#define endl '\n'
int n,ans;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n,ll=0,rl=0;
    while(l<=r){
        l++;
        int rneed=a[l];
        while(rneed&&l<r){
            if(c[l]!=c[r]) ans+=rneed;
            a[r]-=rneed;
            if(a[r]<0){
                rneed=0-a[r];
                if(c[l]!=c[r]) ans+=a[r];
                a[r]=0;
                r--;
            }else{
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}