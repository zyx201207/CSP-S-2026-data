#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,char>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l=0,r=n-1,ans=0;
    while(l<r){
        char x=a[l].second;
        char y=a[r].second;
        if(a[l].first==a[r].first){
            if(x!=y){
                ans+=a[l].first;
            }
            l++,r--;
        }else{
            if(x!=y){
                ans+=min(a[l].first,a[r].first);
            }
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                r--;
            }else{
                a[r].first-=a[l].first;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}