#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
struct no{
    long long len;char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=1,r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
    }
    while(l<r){
        if(a[l].c==a[r].c){
            if(a[l].len<a[r].len) {a[r].len-=a[l].len;l++;}
            else { if(a[r].len<a[l].len) {a[l].len-=a[r].len;r--;} else { if(a[l].len==a[r].len) {l++;r--;} } }
        }else{
            if(a[l].len<a[r].len) {ans+=a[l].len;a[r].len-=a[l].len;l++;}
            else{ if(a[r].len<a[l].len) {ans+=a[r].len;a[l].len-=a[r].len;r--;} else {if(a[l].len==a[r].len) {ans+=a[l].len;l++;r--;}} }
        }
    }
    cout<<ans;
    return 0;
}
