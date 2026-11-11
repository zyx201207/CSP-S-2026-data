#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,ans=0;
        long long d;
        long long x[200010]={};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int l=1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                if(x[mid]==x[i]+2*d-1 && x[i+1]==x[i]+d-1 && x[i+2]==x[i]+d){
                    ans++;
                    break;
                }else if(x[mid]>x[i]+2*d-1){
                    r=mid;
                }else{
                    l=mid+1;
                }
                if(l==r && x[l]!=x[i]+2*d-1){
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
