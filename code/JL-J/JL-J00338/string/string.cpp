#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],b[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    ll L=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        b[i]=a[i];
    }
    ll now=0;
    ll ans=0;
    int r=n,lst=a[r];
    for(int i=1;i<=n;i++){
        now+=b[i];
        while(a[i]){
            if(r<=i){
                break;
            }
            if(c[r]!=c[i]){
                ans+=min(lst,a[i]);
            }
            if(lst<=a[i]){
                a[i]-=lst;
                lst=a[--r];
            }
            else{
                lst-=a[i];
                break;
            }
        }
        if(now>=L/2) break;
    }
    cout<<ans<<'\n';
    return 0;
}
