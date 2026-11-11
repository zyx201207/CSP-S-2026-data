#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int ans2=0,ans1=0,ansn=0,ansn1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)ansn=a[i];
        else ansn=(ansn&a[i]);
        ans1=max(ans1,a[i]);

    }
    if(m){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                ans2=max(ans2,(a[i]&a[j]));
            }
        }
        cout<<ans2;
    }
    if(m==1)cout<<ans1;
    if(m==n)cout<<ansn;
    if(m==n-1)cout<<ansn1;
    return 0;
}
