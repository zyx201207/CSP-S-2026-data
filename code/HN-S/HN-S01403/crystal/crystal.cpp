#include <bits/stdc++.h>

using namespace std;
int a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,f = 0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }int l = a[1],r = a[n],mid;

    while(1){
        mid = (l+r)/2;
        int sum = 0;
        for(int i = 1;i<=n;i++){
            if(a[i]<=mid){
                sum+=mid-a[i];
            }else{
                break;
            }
        }if((r-l) == 1){
            f = l;
            break;
        }
        if(sum>m){
            r-=(r-l)/2;
        }else if(sum == m){
            f = mid;
            break;
        }else{
            l+=(r-l)/2;
        }


    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(a[i]<=f)cnt++;
    }cout<<cnt;

    return 0;
}
