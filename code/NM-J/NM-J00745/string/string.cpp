#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,l,r;
long long ans;
int a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    l=1,r=n;
    while(l<r){
        while(a[l]>a[r]){
            a[l]-=a[r];
            if(b[l]!=b[r])ans+=a[r];
            r--;
        }
        if(b[l]!=b[r])ans+=a[l];
        a[r]-=a[l];
        l++;
    }
    cout<<ans;
    return 0;
}
