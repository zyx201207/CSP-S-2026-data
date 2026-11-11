#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=5e5+10;
int n,m,ans,raw[MAXN],delta,pre_delta,min_idx,max_ans,tmp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>raw[i];
    sort(raw+1,raw+n+1);
    for(int i=1;i<=n;i++){
        delta=raw[i]-raw[i-1];
        tmp=pre_delta+ans*delta;
        ans++;
        if(tmp<=m)pre_delta=tmp;
        else{
            while(tmp>m){
                tmp-=(raw[i]-raw[min_idx]);
                min_idx++;
                ans--;
            }
        }
        pre_delta=tmp;
        max_ans=max(max_ans,ans);
    }
    cout<<max_ans;
    return 0;
}