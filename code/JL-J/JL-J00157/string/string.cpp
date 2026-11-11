#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
ll ans=0;
char ch[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int l=1,r=n;
        while(l<r){
        if(ch[l]!=ch[r]){
            ans+=min(a[l],a[r]);
        }
        ll minn=min(a[l],a[r]);
            a[l]-=minn;
            a[r]-=minn;
            if(a[l]==0)l++;
            if(a[r]==0)r--;
    }
    cout<<ans;
    return 0;
}
