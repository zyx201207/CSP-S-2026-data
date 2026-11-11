#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,a[N],ans;
char b[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i]>>b[i];}
    int l=0,r=n-1;
    while(l<=r){
        //cout<<l<<' '<<r;
       // cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<b[l]<<' '<<b[r]<<' '<<ans<<endl;
        if(b[l]==b[r]){

            if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
            else if(a[l]>a[r])a[l]-=a[r],a[r]=0,r--;
            else if(a[l]==a[r])r--,l++;

        }
        else{
            if(a[l]<a[r])a[r]-=a[l],ans+=a[l],a[l]=0,l++;
            else if(a[l]>a[r])a[l]-=a[r],ans+=a[r],a[r]=0,r--;
            else if(a[l]==a[r])ans+=a[r],r--,l++;
        }

    }
    cout<<ans;
}
