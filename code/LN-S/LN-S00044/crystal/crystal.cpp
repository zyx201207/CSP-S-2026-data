#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> a(100010);
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long len = a[1] - a[0];
    long long k = m/len;
    long long ans=0;
    while(100010){
        ans++;
        if((ans*(ans+1)/2)>k)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
