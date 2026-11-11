#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,a[200005],ans,l_,r_;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    l_=a[l];
    r_=a[r];
    while(1){
        if(l>=r){
            break;
        }
        if(c[l]!=c[r]){
            if(l_<r_){
                ans+=l_;
                r_-=l_;
                l++;
                l_=a[l];
            }
            else if(l_>r_){
                ans+=r_;
                l_-=r_;
                r--;
                r_=a[r];
            }
            else{
                ans+=r_;
                r--;
                l++;
                r_=a[r];
                l_=a[l];
            }
        }
        else{
            if(l_<r_){
                r_-=l_;
                l++;
                l_=a[l];
            }
            else if(l_>r_){
                l_-=r_;
                r--;
                r_=a[r];
            }
            else{
                r--;
                l++;
                r_=a[r];
                l_=a[l];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
