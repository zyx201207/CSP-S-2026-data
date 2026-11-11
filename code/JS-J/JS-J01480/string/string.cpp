#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    int n;
    cin>>n;
    long long ssiz=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ssiz+=a[i];
    }
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        if(c[l]!=c[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }
            else{
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                l++;
                r--;
            }
            else{
                a[l]-=a[r];
                r--;
            }
        }
        if(l>=r){
            break;
        }
    }
    cout<<ans;
    return 0;
}
