#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200001];
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int p=1,q=n;
    ll ans=0;
    while(p<=q){
        if(a[p]>=a[q]){
            if(c[p]!=c[q]){
                ans+=a[q];
            }
            a[p]-=a[q];
            a[q]=0;
            q--;
            if(a[p]==0){
                p++;
            }
        }
        else{
            if(c[p]!=c[q]){
                ans+=a[p];
            }
            a[q]-=a[p];
            p++;
        }
    }
    cout<<ans;
    return 0;
}