#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;

int n,m;
int a[N];
int sum[N];
int d[N];


signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];

    int ans=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            int v=a[i]*(i-j+1)-sum[i]-sum[j-1];
            if(v<=m){
                ans=max(ans,i-j+1);
                break;
            }

        }
    }
    cout<<ans;

}

