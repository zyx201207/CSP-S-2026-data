#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500005],b[500005],tmp;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        b[i]=(a[i]-a[i-1])*i+b[i-1];
        //cout<<b[i]<<" ";
    }
    for(int i=0;i<n;i++){
        tmp=i+ans-1;
        for(int j=tmp;j<n;j++){
            if(b[j]-b[i]-(a[j]-a[i])*i<=m){
                ans=max(ans,j-i+1);
            }
            else{
                break;
            }
        }

    }
    cout<<ans;
    return 0;
}
