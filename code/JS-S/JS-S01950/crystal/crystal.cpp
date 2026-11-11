#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
deque<long long>dq;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    dq.emplace_back(a[1]);
    long long cost=0,size=1,maxn=INT_MIN;
    for(int i=2; i<=n; i++){
        cost+=(a[i]-dq.back())*size;
        while(size!=0 && cost>m){
            cost-=a[i]-dq.front();
            dq.pop_front();
            size--;
        }
        size++; dq.emplace_back(a[i]);
        maxn=max(maxn,size);
    }
    cout<<maxn<<"\n";
    return 0;
}
