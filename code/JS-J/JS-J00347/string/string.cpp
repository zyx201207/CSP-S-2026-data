#include<bits/stdc++.h>
using namespace std;
long long n,a[222222],q=1,ans,p;
char c[222222];
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    p=n;
    while(q<p){
        if(c[q]!=c[p]){
            if(a[q]>a[p]){
                a[q]-=a[p];
                ans+=a[p];
                p--;
            }else{
                a[p]-=a[q];
                ans+=a[q];
                q++;
            }
        }else{
            if(a[q]>a[p]){
                a[q]-=a[p];
                p--;
            }else{
                a[p]-=a[q];
                q++;
            }
        }
    }
    cout<<ans;
    return 0;
}
