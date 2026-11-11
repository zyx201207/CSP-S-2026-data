#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5+10;
typedef long long ll;
int n;
ll m,a[mxN],b[mxN],bst[mxN],len;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    len=n-1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    //len=max(i,n-len+1); 
    while(m){
        ll mi=INT_MAX;
        int pos=-1;
        for(int i=1;i<=len;i++){
            if(b[i]>b[i+1] and b[i]!=0) break;
            else{
                while(b[i]==0) i++;
            }
            if(mi>b[i] and b[i]!=0){
                mi=b[i];
                pos=i;
            }
        }
        a[pos]+=b[pos];
        m-=b[pos];
    }
    for(int i=1;i<=n;i++) bst[a[i]]++;
    ll mx=INT_MIN;
    for(int i=1;i<=1e12;i++) mx=max(bst[i],mx);
    cout<<mx;
    return 0;
}
