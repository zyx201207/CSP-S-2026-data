#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    char b[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l]>a[r]){
            if(b[l]==b[r]){
                a[l]-=a[r];
                r-=1;
            }
            else{
                a[l]-=a[r];
                ans+=a[r];
                r-=1;
            }
        }
        else if(a[l]<a[r]){
            if(b[l]==b[r]){
                a[r]-=a[l];
                l+=1;
            }
            else{
                a[r]-=a[l];
                ans+=a[l];
                l+=1;
            }
        }
        else {
            if(b[l]==b[r]){
                l++;
                r--;
            }
            else{
                ans+=a[l];
                l++;
                r--;
            }
        }

    }
    cout<<ans;
    return 0;
}

