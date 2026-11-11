#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],tmp,len,l,r,ls,rs,ans;
char c[200005];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        len+=a[i];
    }
    l=1;
    r=n;
    len/=2;
    while(l<=r){
        if(a[l]>a[r]){
            if(c[l]!=c[r])ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        else if(a[l]==a[r]){
            if(l==r)break;
            if(c[l]!=c[r])ans+=a[l];
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
        else{
            if(c[l]!=c[r])ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
