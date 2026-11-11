#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[200010],s,l,r,i,j;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    r=n;
    j=s;
    s=s/2;
    l=1;
    for(;i<s&&j>s;){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans=ans+min(a[r],j-s);
            }
            j=j-a[r];
            a[l]=a[l]-a[r];
            r--;
        }
        else{
            if(c[l]!=c[r]){
                ans=ans+min(a[l],s-i);
            }
            i=i+a[l];
            a[r]=a[r]-a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
