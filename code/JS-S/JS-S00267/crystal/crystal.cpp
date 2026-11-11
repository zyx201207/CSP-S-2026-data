#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,res=0;
ll m,a[500005],s[500005];
int check2(int pos){
    int l=0,r=pos+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        ll res2=s[pos]-s[mid]-1ll*(a[pos]-a[mid])*(mid-1);
        if(res2>m){
            l=mid;
        }else{
            r=mid;
        }
    }
    return pos-r+1;
}
bool check(int num){
    for(int i=n;i>=1;i--){
        if(check2(i)>=num){
            return true;
        }
    }
    return false;
}
int bs(){
    int l=0,r=n+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            res=l=mid;
        }else{
            r=mid;
        }
    }
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+1ll*(a[i]-a[i-1])*(i-1);
    }
    cout<<bs();
    return 0;
}
