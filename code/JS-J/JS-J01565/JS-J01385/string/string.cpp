#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l,r,ans=0;
    long long a[200010];
    char c[200010];
    cin>>n;
    l=1;r=n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    while(l<r){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]-=a[r];
        }else{
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]-=a[l];
        }
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
