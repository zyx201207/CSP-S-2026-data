#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[10005],cnt[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> qp;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        qp.push(a);
    }
    for(int i=1;i<n;i++){
        int a,b;
        a=qp.top();
        qp.pop();
        b=qp.top();
        qp.pop();
        cnt[i]=b-a;
        qp.push(b);
    }
    int ao=0;
    for(int i=1;i<n;i++){
        if(cnt[i+1]!=cnt[i-1]){
            ao=1;
            break;
        }
    }
    if(ao==0){
        int k=1,sum=0;
        while(sum<=m){
            if(sum+=k*cnt[1]>m) break;
            sum+=k*cnt[1];
            k++;
        }
        cout<<k;
        return 0;
    }
    int ans1=0;
    for(int i=1;i<n;i++){
        int ans=0,xy=1;
        for(int j=i;j<n;j++){
            if(cnt[j]==cnt[j-1]){
                ans1=max(ans1,(j-i+2));
                xy++;
                continue;
            }
            if(ans+=cnt[j]*xy>m){
                break;
            }
            ans1=max(ans1,(j-i+2));
            xy++;
        }
    }
    cout<<ans1;
    return 0;
}
