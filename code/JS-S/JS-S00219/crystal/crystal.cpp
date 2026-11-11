#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
const int maxn=5e5+10;
ll a[maxn],s[maxn];
int n;
ll m;
bool check(int i,int j){
    int sum=j-i+1;
    if(a[j]*sum-(s[j]-s[i-1])<=m)return 1;
    else return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    int mx=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                r=mid-1;
            }
            else l=mid+1;
        }
        mx=max(mx,i-l+1);
    }
    cout<<mx;
    return 0;
}
