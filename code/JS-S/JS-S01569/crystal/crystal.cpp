#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
ll b[N];
int n,m;
bool check(int mid,int id){
    int sumx=mid*a[id]-(b[id]-b[id-mid]);
    return sumx<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        int l=0,r=i+1;
        while(l+1<r){
            int mid=(l+r)/2;
            if(check(mid,i))l=mid;
            else r=mid;
        }
        ans=max(ans,l);
    }
    cout<<ans;
    return 0;
}
