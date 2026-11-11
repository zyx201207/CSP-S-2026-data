#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long n,len,a[N],l,r,ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    /*
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<"\n";
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";cout<<"\n";
    //*/
    l=1;r=n;
    while((l<=r)){
        bool ok=0;
        while(a[l]>=a[r]&&(l<=r)){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
            ok=1;
        }
        if(ok) {
            if(c[r]!=c[l]) ans+=a[l];
            a[r]-=a[l];
            l++;
            continue;
        }
        //if(a[l]<1) l++;
        while(a[r]>a[l]&&(l<=r)){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
            ok=1;
        }
        if(ok){
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            r--;
            continue;
        }
        //if(a[r]<1) r--;
        //if(l==r) break;
    }

    cout<<ans;
    return 0;
}
