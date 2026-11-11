#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,ans;
struct d{
    int num;
    char ch;
    ll pre;
}a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].ch;
        a[i].pre=a[i-1].pre+a[i].pre;
    }
    ll l=1,r=n;
    if(a[n].pre%2==0)t=a[n].pre/2;
    else t=a[n].pre/2+1;
    for(ll l=1;l<=n/2;l++){
        for(ll r=n;r>=n/2;r--){
            if(a[l].ch==a[r].ch){
            l++;
            r--;
            continue;
            }
        ll s=t-(a[r].pre-a[r].num-t+1);
        ll e=s+a[r].num;
        ll g=abs(a[l].pre-e)-abs(a[l].pre-a[l].num)+1;
        if(g<1)break;
        else ans+=g;
        if((a[l].pre>=t||a[r].pre-a[r].num<=t)&&t%2==1)ans--;
        }
    }
    cout<<ans;
    return 0;
}
//string