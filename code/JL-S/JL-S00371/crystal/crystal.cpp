#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
signed main(){
    //timecost:30m expect:100pts
    //test1:ok 0ms
    //test2:ok 0ms
    //test3:ok 3ms max.
    //test4:ok 193ms max.
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int ans=1;
    int i=1,j=0,sum=a[1]-a[0];
    while(i<n){
        i++;sum+=(a[i]-a[i-1])*(i-j);
        while(sum>m){
            sum-=(a[i]-a[j]);j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
