#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int fla=1,flb=1;
    cin >> n >> m >> a[1] >> a[2];
    if(a[1]!=1 || a[2]!=2) fla=0;
    long long cha=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++){
        cin >> a[i];
        if(a[i]!=i) fla=0;
        if(flb==1){
            if(abs(a[i]-a[i-1])!=cha) flb=0;
        }
    }
    if(fla==1){
        for(int i=2;i<=n;i++){
            if(m>=i-1){
                m-=(i-1);
            }
            else{
                cout << i-1;
                break;
            }
        }
        return 0;
    }
    else if(flb==1){
        m/=cha;
        for(int i=2;i<=n;i++){
            if(m>=i-1){
                m-=(i-1);
            }
            else{
                cout << i-1;
                break;
            }
        }
        return 0;
    }
    sort(a+1,a+1+n);
    int maxn=1,x=2;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i+1]) continue;
        long long k=m,j=x-1;
        while(j>=1){
            if(a[i]-a[j]<=k){
                k-=(a[i]-a[j]);
            }
            else break;
            j--;
        }
        if(maxn<i-j){
            maxn=i-j;
        }
        x=i+1;
    }
    cout << maxn;
    return 0;
}