#include<bits/stdc++.h>
using namespace std;
int n,a[214514],b[214514];
char c[214514],d[214514];
long long s,p=1,k=1,l=1,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],s+=a[i];
    for(int i=1;i<=n;i++) b[i]=a[n-i+1],d[i]=c[n-i+1];
    while(k<=n&&l<=n){
        if(a[k]<b[l]){
            if(c[k]!=d[l]) ans+=a[k];
            b[l]-=a[k];a[k]=0;k++;
        }
        else if(a[k]>b[l]){
            if(c[k]!=d[l]) ans+=b[l];
            a[k]-=b[l];b[l]=0;l++;
        }
        else {
            if(c[k]!=d[l]) ans+=b[l];
            a[k]=b[l]=0;l++;k++;
        }
    }
    cout<<ans/2;
    return 0;
}
