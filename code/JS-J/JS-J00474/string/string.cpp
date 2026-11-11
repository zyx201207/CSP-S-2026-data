#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
                ans+=a[r];
            }
            if(a[l]<a[r]){
                a[r]-=a[l];
                r++;
                ans+=a[l];
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            if(a[l]<a[r]){
                a[r]-=a[l];
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}


