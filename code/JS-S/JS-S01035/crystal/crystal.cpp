#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int n,m;
int a[N],b[N],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
    int l=0,k=1,j=n-1;
    for (int i=n-1;i>=1;i--){
        if (m>=l+b[i]) {
            l+=b[i];
            m-=l;
            k++;
        }else {
            ans=max(ans,k);
            k--;
            l-=b[j];
            m+=(j-i)*b[j];
            j--;
            i++;
        }
    }
    ans=max(ans,k);
    cout<<ans;
    return 0;
}
