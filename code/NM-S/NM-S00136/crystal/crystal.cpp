#include<bits/stdc++.h>
using namespace std;
const int nn=5e5+5;
typedef long long ll;
int n,ans=1;
ll m,a[nn];
int find(int l,int r){
    if(l==r){
        return ans;}
    ans=0;
    int mid=(l+r)/2,fix;
    for(int i=1;i<=mid;i++){
        ll st=a[mid];
        ll diff;
        diff=a[mid]-a[i];
        if(diff<0){continue;
		}
        if(diff+fix>m){continue;}
        else{
            fix+=diff;ans++;}
    }
    int oldans=ans;
    if(fix<=m){
           ans=max(oldans,find(mid+1,r));
    }
    else{
        ans=max(oldans,find(l,mid));
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];}
    sort(a+1,a+n+1);
    cout<<find(1,n);
    return 0;}
