#include <bits/stdc++.h>
using namespace std;
long long m[299999];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    string q;
    char q1,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        cin>>q1;
        q+=q1;
    }
    long long l=0,r=n-1;
    while(l+1<r){
        if(q[l]==q[r]){
            if(m[l]>m[r]){
                m[l]=m[l]-m[r];
                r=r-1;
            }else if(m[l]==m[r]){
                r=r-1;
                l=l+1;
            }else {
                m[r]=m[r]-m[l];
                l=l+1;
            }
        }else {
            if(m[l]>m[r]){
                ans+=m[r];
                m[l]=m[l]-m[r];
                r=r-1;
            }else if(m[l]==m[r]){
                ans+=m[r];
                r=r-1;
                l=l+1;
            }else {
                ans+=m[l];
                m[r]=m[r]-m[l];
                l=l+1;
            }
        }
    }
            if(q[l]==q[r]){
            if(m[l]>m[r]){
                m[l]=m[l]-m[r];
                r=r-1;
            }else if(m[l]==m[r]){
                r=r-1;
                l=l+1;
            }else {
                m[r]=m[r]-m[l];
                l=l+1;
            }
        }else {
            if(m[l]>m[r]){
                ans+=m[r];
                m[l]=m[l]-m[r];
                r=r-1;
            }else if(m[l]==m[r]){
                ans+=m[r];
                r=r-1;
                l=l+1;
            }else {
                ans+=m[l];
                m[r]=m[r]-m[l];
                l=l+1;
            }
        }
    cout<<ans;

    return 0;
}
