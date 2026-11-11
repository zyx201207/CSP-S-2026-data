#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout << ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout << ans;
    }else{
        cout << 32768;
    }
    return 0;
}
