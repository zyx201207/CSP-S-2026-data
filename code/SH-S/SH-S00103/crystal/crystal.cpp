#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int j = 0;j<n;j++){
        int ans=0,cnt=0;
        for(int z = 0;z<n;z++){
            if(a[j]-a[z]>=0){
                ans+=a[j]-a[z];
            }
        }
        if(ans==m){
            for(int x = 0;x<n;x++){
                if(a[x]<=a[j]) cnt++;
            }
            cout<<cnt;
            break;
        }
    }
    return 0;
}
