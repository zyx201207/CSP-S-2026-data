#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
int l=1,r;
ll now=1;
ll s[N];
ll cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
    }
    r=n;
    while(l<=r){
        ll x=s[l]-now+1,y=s[n]-now+1-s[r-1];
        if(x>y){
            if(c[l]!=c[r]){
                cnt+=y;
            }
            r--;
            now+=y;
        }else{
            if(c[l]!=c[r]){
                cnt+=x;
            }
            l++;
            now+=x;
        }
    }
    cout<<cnt;
    return 0;
}
