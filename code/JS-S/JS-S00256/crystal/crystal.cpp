#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
    freopen(crystal.in,"r",stdin);
    freopen(crystal.out,"w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=-1;
    for(int i=2;i<=n;i++){
        long long cha=0;
        int cnt=1,j=i-1;
        while(j>0&&cha<m){
            cha+=a[i]-a[j];
            if(cha<=m){
                cnt++;
                j--;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
