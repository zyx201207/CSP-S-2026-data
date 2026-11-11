#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll mp[500010] = {};
ll q[500010] = {};
ll jishuan(int l,int r){
    ll ret = q[r]-q[l-1];
    ret = ret-((mp[n]-mp[r])*(r-l+1));
    return ret;
}
int erfen(int st){
    int l = st,r = n;
    int ans = -1;
    //printf("from%dto:\n",l);
    while(l<=r){
        int mid = (l+r)>>1;
        //printf("    %d %d %d  ret%d long%d  ",l,mid,r,jishuan(st,mid),mid-st+1);
        if(jishuan(st,mid)>m){
            r = mid-1;
            //cout<<"change r\n";
        }else{
            ans = mid;
            l = mid+1;
            //cout<<"change l\n";
        }
        //cout<<endl;
    }
    return (ans-st+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>mp[i];
    }
    sort(mp+1,mp+n+1);
    for(int i = 1;i<=n;i++){
        q[i] = q[i-1]+(mp[n]-mp[i]);
    }//cout<<"!!!"<<endl;
    ll nowm = 0;
    int i = 1;
    int ans = -1;
    //cout<<jishuan(2,4)<<endl;
    for(;i<=n;i++){
        ans = max(erfen(i),ans);
    }
    cout<<ans;
    return 0;
}
