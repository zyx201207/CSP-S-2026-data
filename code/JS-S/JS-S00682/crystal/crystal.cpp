#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500009],b[500009],ans=0;
bool check(int x){
    for(int i=1;i<=n;i++){
        b[i]=a[i]-x>0?a[i]-x:x-a[i];
    }
    int cnt=0,have=m;
    for(int i=n;i>=1;i--){
        if(a[i]>x) continue;
        if(a[i]==x) cnt++;
        if(a[i]<x){
            if(have<b[i]) break;
            have-=b[i];
            cnt++;
        }
    }
    if(cnt>ans){
        ans=cnt;
        return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    int lt=1,rt=maxn;
    while(lt<=rt){
        int mid=(lt+rt)/2;
        if(check(mid)){
            rt=mid-1;
        }
        else{
            lt=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
