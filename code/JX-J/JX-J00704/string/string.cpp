#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else{
                a[l]-=a[r];
                r--;
            }
        }else if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else{
                a[r]-=a[l];
                l++;
            }
        }else{
            if(c[l]!=c[r]){
                ans+=a[r];
                l++,r--;
            }else{
                l++,r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
