#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,len=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int left=1,right=n,ans=0;
    while(left<right){
        if(a[right]>a[left]){
            ans+=(c[right]!=c[left])*a[left];
            a[right]-=a[left],left++;
        }
        else if(a[right]==a[left]){
            ans+=(c[right]!=c[left])*a[left];
            left++,right--;
        }
        else{
            ans+=(c[right]!=c[left])*a[right];
            a[left]-=a[right],right--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
