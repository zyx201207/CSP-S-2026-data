#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>a;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    if(a[2]-a[1]>m) {
        cout<<1;
        return 0;
    }
    if(a[1]==a[2]&&a[2]==a[3]){
        int flag=0;
        for(int i=4;i<n;i++){
            if(a[i]!=a[i+1]) flag=1;
        }
        if(flag==0) cout<<n;
        return 0;
    }
    int l=1;
    int r=2;
    int ans=0;
    int sum=1;
    int m1=m;
    int N=1e7+5;
    while(N--){
        if(r==n&&l==0){
                break;
            }
            if(l==0) {
                r++;
                l=r-1;
                ans=max(ans,sum);
                sum=1;
                m1=m;
            }
        int ab=a[r]-a[l];
        m1=m1-ab;
        if(m1>=0){
            sum++;
            l--;
        }
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?
//5 5
//1 2 4 8 9

