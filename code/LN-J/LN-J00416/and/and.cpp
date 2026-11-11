#include<iostream>
#include<vector>
#define N 2005
using namespace std;
int m,n,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ans=0x3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans&=a[i];
    }
    cout<<ans;
}
