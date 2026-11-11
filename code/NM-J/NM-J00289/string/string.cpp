#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
char a1,a2,b1,b2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r){
        if(c[l]!=c[r]){
            if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
                continue;
            }
            if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
                continue;
            }
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
                continue;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
                continue;
            }
            if(a[l]==a[r]){
                l++;
                r--;
                continue;
            }
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}