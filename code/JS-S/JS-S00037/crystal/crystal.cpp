#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=500005;
int a[MAXN];
int d[MAXN];
int ans1[MAXN];
ll m;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    ll cur=0;//used m
    queue<int> q;
    q.push(1);//record xiabiao
    ans1[1]=1;
    for(int i=2;i<=n;i++){
        cur+=(q.size()*d[i]);
        q.push(i);
        if(cur>m){
            while(cur>m){
                int x=a[q.front()];
                q.pop();
                cur-=(a[i]-x);
            }
        }
        ans1[i]=q.size();
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,ans1[i]);
    }
    cout<<ans;





    return 0;
}
