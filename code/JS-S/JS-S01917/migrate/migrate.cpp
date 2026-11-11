#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T,ttt;
    cin>>ttt>>T;
    while(T--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(a[i+1]-a[i-1]<=d&&a[i+2]-a[i]<=d&&a[i+2]-a[i-1]>d){
                int l=i-1;
                while(l>2&&((a[l+1]-a[l-1]<d)!=(a[l]-a[l-2]<d))){
                    l--;
                }
                int r=i+2;
                while(r<n-2&&((a[r+1]-a[r-1]<d)!=(a[r+2]-a[r]<d))){
                    r++;
                }
                ans+=(i-l)*(r-i-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
