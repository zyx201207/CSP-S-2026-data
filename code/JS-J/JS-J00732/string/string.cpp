#include <bits/stdc++.h>
using namespace std;

int a[200010];
char c[200010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int j=n;
    for(int i=1;i<j;i++){
        while(i<j&&a[i]>=a[j]){
            if(c[i]!=c[j]){
                ans+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
        if(i<j){
            if(c[i]!=c[j]){
                ans+=a[i];
            }
            a[j]-=a[i];
        }
    }
    cout<<ans;
    return 0;
}
