#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<char,int>a[200005];
int n;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }
    int ans=0;
    for(int i=1,j=n;i<=j;){
        int p=min(a[i].second,a[j].second);
        if(a[i].first!=a[j].first)ans+=p;
        a[i].second-=p;
        a[j].second-=p;
        if(a[i].second<=0)i++;
        if(a[j].second<=0)j--;
    }
    cout<<ans;
    return 0;
}
