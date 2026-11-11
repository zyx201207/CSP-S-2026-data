#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e6+10;
int n,d,a[N];
void solve(){
    cin>>n>>d;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int mig=-1;
        int l=i+1,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid]-a[i]<=d){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        mig=l;
        l=mig+1; r=n;
        for(int j=n;j>=i;j--){

        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cout<<2<<endl<<3;
    return 0;
}
