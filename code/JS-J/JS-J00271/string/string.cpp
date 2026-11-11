#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+5;
int n;
int a[maxn];
char c[maxn];
int ans;
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    int l=1,r=n;
    while(l!=n){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]=0;
            r--;
        }else if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]=0;
            l++;
        }else{
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[l]=a[r]=0;
            l++;r--;
        }
    }
    cout << ans;
}
