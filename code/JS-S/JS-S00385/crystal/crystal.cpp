#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n,a[500009],ans=0,c;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            int b=m,z=1;
        for(int j=0;j<i;j++){
                int c=a[i]-a[j];
            if(c<=b&&c>=0){
                z++;
                b=m-c;
                ans=max(z,ans);
            }
        }
    }
    cout<<ans;
    return 0;
}
