#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
ll n,m,v,c,a[N],b[N],s;
bool check(int l,int r,int g){
    ll y=b[g]-b[r-1];
    ll t=(g-r+1)*a[g];
    if(y+m>=t){
        return true;
    }
    else{
        return false;
    }
}
ll erfen(int r,int l){
    int mid=(l+r)/2,g=l;
    while(r<mid){

        if(check(l,mid,g)){
            l=mid;
        }
        else{
            r=mid+1;
        }mid=(l+r)/2;
    }
    return g-r+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
 //   cout<<b[n]<<endl;
    for(int i=1;i<=n;i++){
        s=max(erfen(1,i),s);
    }
    cout<<s<<endl;
    return 0;
}
