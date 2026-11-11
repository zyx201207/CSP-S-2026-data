#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int m;
ll a[500005];
ll s[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s[0]=0ll;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){s[i]=s[i-1]+a[i];}

    int ans=0;
    for (int i=2;i<=n;i++){
        int l=0;
        int r=i-1;
        int mid=(l+r)/2;
        while(l<r){
            int mid=(l+r)/2;

            if (s[i-1]-s[mid]+m>=a[i]*(i-1-mid)){
                r=mid;
            }
            else {
                l=mid+1;
            }
        }
        //cout<<(i-1-l)<<" "<<l<<"\n";
        ans=max(ans,(i-r));
    }
    cout<<ans;

}

