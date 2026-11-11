#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=a[n];
    int j=n;
    int b=m-1;
    while(b--){
        ans=(s&a[j-1]);
        j--;
    }
    cout<<ans;
    return 0;
}
