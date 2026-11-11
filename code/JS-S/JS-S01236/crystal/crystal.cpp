#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll a[N],b[N],m;
int n;
bool check(int mid){
    for(int i=1;i<=n-mid+1;i++){
        ll sum=b[i+mid-1]-b[i-1];
        if(a[i+mid-1]*mid-sum<=m){
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int left=1,right=n,mid;
    int ans=-1;
    while(left<=right){
        mid=left+right>>1;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
