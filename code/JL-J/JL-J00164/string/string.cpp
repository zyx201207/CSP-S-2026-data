#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],ans=0;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]<a[r])a[r]-=a[l],ans+=a[l],l++;
            else if(a[r]<a[l])a[l]-=a[r],ans+=a[r],r--;
            else if(a[l]==a[r])ans+=a[r],l++,r--;
        }else{
            if(a[l]<a[r])a[r]-=a[l],l++;
            else if(a[r]<a[l])a[l]-=a[r],r--;
            else if(a[l]==a[r])l++,r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}