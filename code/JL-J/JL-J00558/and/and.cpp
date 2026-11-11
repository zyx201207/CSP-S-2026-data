#include <bits/stdc++.h>
using namespace std;
int n,m,t;
long long a[300030];
long long dp,max1=-1,max2=-1,min1=INT_MAX;
long long dpp;
bool ff=true,fff=true;
long long q,w,e,r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1) dp=dp&a[i];
        else dp=a[1];
        if(a[i]>max1){
            max1=a[i];
            t=i;
        }
        if(a[i]!=i-1){
            ff=false;
        }
        if(a[i]>=4){
            fff=false;
        }
        if(a[i]==0){
            q++;
        }else if(a[i]==1){
            w++;
        }else if(a[i]==2){
            e++;
        }else if(a[i]==3){
            r++;
        }
    }
    if(m==1){
        cout<<max1;
        return 0;
    }
    if(m==2){
        sort(a+1,a+n+1);
        for(int i=n;i>=1;i--){
            for(int j=i-1;j>=1;j--){
                max2=max(max2,(a[i]&a[j]));
            }
        }
        cout<<max2;
        return 0;
    }
    if(m==n){
        cout<<dp;
        return 0;
    }
    if(m==n-1){
        sort(a+1,a+n+1);
        long long dp1=a[n];
        for(int i=n-1;i>=2;i--){
            dp1=(dp1&a[i]);
        }
        cout<<dp1;
        return 0;
    }
    if(ff){
            long long dp2=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            dp2=(dp2&a[i]);
        }
    cout<<dp2;
    return 0;
    }
    if(fff){
        if(r>=m){
            cout<<3;
        }else if(r+e>=m){
            cout<<2;
        }else if(r+e+w>=m){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    sort(a+1,a+n+1);
    dpp=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        dpp=(dpp&a[i]);
    }
    cout<<dpp;
    return 0;
}
