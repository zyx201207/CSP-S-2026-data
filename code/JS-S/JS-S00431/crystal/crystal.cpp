#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;ll m;cin>>n>>m;
    vector<ll> val(500500,0);
    vector<ll> a(500500,0);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    sort(val.begin()+1,val.begin()+n+1);
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+val[i];
    }
    int s=1,e=n;
    while(s!=e){
        int mid=(s+e+1)/2;
        bool t=0;
        for(int i=mid;i<=n;i++){
            if((val[i]*mid-a[i]+a[i-mid])<=m){
                t=1;
                break;
            }
        }
        if(t){
            s=mid;
        }
        else{
            e=mid-1;
        }
    }
    cout<<s;
    return 0;
}
