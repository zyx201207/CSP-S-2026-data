#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans =0 ;
    cin>>n;
    int a[1000000010][1000000010];
    for(int i = 0;i<n;i++){
        for(int  j = 0;j<2;j++){
            cin>>a[i][j];

        }
        ans+=a[i][0];
    }
    cout<<ans/n;
    return 0;
}
