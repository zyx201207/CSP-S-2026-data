#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
string b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,f;
    cin>>n;

    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i];


    }
    long long ans=0;
    int l = 1,r=n;
    while(l<r){
        if(a[l]>a[r]){
            f=1;
            if(b[l]==b[r]){

                a[l]-=a[r];r--;
            }
            else{
                a[l]-=a[r];ans+=a[r];r--;
            }

        }
        if(a[l]==a[r]){
            if(b[l]==b[r]){
                l++;r--;
            }
            else{
                ans+=a[l];
                l++;r--;
            }
        }
        if(a[l]<a[r]){
                f=0;
            if(b[l]==b[r]){
                a[r]-=a[l];
                l++;
            }
            else{
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
        }
    }
    if(r+1==l){
        cout<<ans<<endl;
    }
    else{
        if(f){
            cout<<ans<<endl;
        }
        else cout<<ans<<endl;
    }

    return 0;
}

