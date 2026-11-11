#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],maxn=0;
map <ll,ll> sum;
ll q[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector <int> num;
    num.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(sum[a[i]]==0) num.push_back(a[i]);
        sum[a[i]]++;
    }
    sort(a+1,a+n+1);
    sort(num.begin(),num.end());
    for(int i=1;i<num.size();i++){
        bool flag=0;
        ll det=0;
        ll x=upper_bound(a+1,a+n+1,num[i])-a-1;
        for(ll j=x;j>=1;j--){
            det+=num[i]-a[j];
            if(det>m){
                flag=1;
                maxn=max(x-j,maxn);
                break;
            }
        }   
        if(!flag) maxn=max(maxn,x);
    }
    cout<<maxn;
}