#include<bits/stdc++.h>
using namespace std;
long long w[200005][35];
long long a[200005],n,k;
set<long long> se;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<long long>());
    for(long long i = 1;i<=n;i++){
        long long t = a[i],ws = 1;
        while(t>0){
            w[i][ws] = t%2;
            t/=2;
            ws++;
        }
        se.insert(i);
    }
    long long ans = 0;
    for(long long i = 31;i>=1;i--){
        long long cnt = 0;
        vector<long long> v;
        for(long long tmp:se){
            if(w[tmp][i] == 1){
                cnt++;
            }
            else{
                v.push_back(tmp);
            }
        }
        if(cnt>=k){
            for(long long tmp:v) se.erase(tmp);
        }
        ans = ans*2+(cnt>=k);
    }
    cout<<ans;
    return 0;
}
