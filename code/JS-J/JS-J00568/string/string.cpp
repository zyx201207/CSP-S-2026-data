#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N],l,r;
char c[N];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    l=1,r=n;
    while(l<r){
        if(a[l]<a[r]){
            if(c[l]!=c[r])
                ans+=a[l];
            a[r]-=a[l++];
        }
        else{
            if(c[l]!=c[r])
                ans+=a[r];
            a[l]-=a[r--];
        }
    }
    cout<<ans;
    return 0;
}
