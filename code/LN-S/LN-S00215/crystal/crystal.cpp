#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],tmp,num,l,r,ans=1;
bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        if(i>=3){
            if(abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])){
                flag=1;
            }
        }
    }
    if(flag==0){
        tmp=a[2]-a[1];
        for(ll i=1;i<=n-1;i++){
            if((1+i)*i/2*tmp<=m){
                ans=max(ans,i+1);
            }
            else break;
        }
        cout<<ans;
        return 0;
    }
    l=1;
    r=1;
    while(l<=r){
        if(r>n)break;
        if(l==r){
            r++;
            continue;
        }
        tmp=(r-l)*(a[r]-a[r-1]);
        if(tmp<=m){
            ans=max(ans,r-l+1);
            m-=tmp;
            if(r+1<=n)r++;
            else{
                l++;
                r++;
            }
        }
        else{
            m+=a[l+1]-a[l];
            if(l+1<=r)l++;
            else{
                l++;
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}
