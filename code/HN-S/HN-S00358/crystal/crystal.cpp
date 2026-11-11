#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,mx;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        if(i==n||a[i]!=a[i+1]){
            int l=0,r=i;
            while(l+1<r){
                int mid=(l+r)>>1;
                if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)) r=mid;
                else l=mid;
            }
            mx=max(mx,i-r+1);
        }
    }
    cout<<mx;
    return 0;
}