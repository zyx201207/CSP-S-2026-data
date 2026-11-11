#include<bits/stdc++.h>
using namespace std;
#define int long long
int len,n,a[200005],ans,cnt;
char ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        len+=a[i];
    }
    int l=1,r=n;
    while(cnt<len/2){
        if(l==r) break;
        if(a[l]<a[r]){
            cnt+=a[l];
            a[r]-=a[l];
            ans+=(ch[l]!=ch[r])*a[l];
            l++;
        }else if(a[l]>a[r]){
            cnt+=a[r];
            a[l]-=a[r];
            ans+=(ch[l]!=ch[r])*a[r];
            r--;
        }else{
            ans+=(ch[l]!=ch[r])*a[l];
            a[l]=a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
