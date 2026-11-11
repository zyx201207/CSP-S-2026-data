#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int num,ans,a[N];
string c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
    }
    int l=1,r=num;
    while(l!=r){
        if(c[l]!=c[r])ans+=min(a[l],a[r]);
        if(a[l]>a[r]){
            a[r]=0;
            a[l]-=a[r];
            r--;
        }
        if(a[r]>a[l]){
            a[l]=0;
            a[r]-=a[l];
            l++;
        }
        if(a[l]==a[r]){
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}