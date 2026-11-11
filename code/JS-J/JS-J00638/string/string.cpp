#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,ans,ll,rr,s,mid;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    l=0,r=n-1;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                --r;
            }
            else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                a[l]=0;
                ++l;
            }
            else if(a[l]==a[r]){
                ans+=a[l];
                a[r]=0;
                a[l]=0;
                --r;
                ++l;
            }
        }
        else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                --r;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                a[l]=0;
                ++l;
            }
            else if(a[l]==a[r]){
                a[r]=0;
                a[l]=0;
                --r;
                ++l;
            }
        }
    }
    cout<<ans<<"\n";
}
