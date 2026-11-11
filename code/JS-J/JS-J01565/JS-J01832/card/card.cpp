#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
int a[N];
int cnt[N];
// int las[N],fir[N],sec[N];
// bool vis[N];
int ans[N];
vector<int>v[N];
// vector<int>t[N];
// bool f[N];
int n,m;
stack<int>sta;
void calc(int k){
    for(int i=k;i<=n;i++){
        vector<int>v;
        while(!sta.empty()){
            v.push_back(sta.top());
            if(sta.top()==a[i]){
                v.clear();
            }
            sta.pop();
        }
        for(int i=(int)v.size()-1;i>=0;i--){
            sta.push(v[i]);
        }
        sta.push(a[i]);
    }
    while(!sta.empty()){
        ans[sta.top()]++;
        sta.pop();
    }
    cout<<endl;
    return;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>m;
    for(int i=1;i<=n;i++)cin >>a[i];
    bool fa=1;
    for(int i=2;i<=n;i++)if(a[i]<a[i-1])fa=0;
    for(int i=1;i<=n;i++){
        v[a[i]].push_back(i);
        cnt[a[i]]++;
    }
    // if(m<=2){
    //     int las,fir=-1;
    //     for(int i=0;i<=v[1][0]-1;i++){
    //         if(a[i]==2){
    //             if(fir==-1)fir=i;
    //             las=i;
    //         }
    //     }
    //     for(int i=v[1].back();i<=n;i++){
    //         if(a[i]==2){
    //             if(fir==-1)fir=i;
    //             las=i;
    //         }
    //     }
    //     for(int )
    //     for(int i=2;i<=n;i++){

    //     }
    //     return 0;
    // }
    if(fa){
        for(int i=1;i<=m;i++)ans[i]=1;
        for(int i=1;i<=n;i++){
            cnt[a[i]]--;
            if(cnt[a[i]]==0){
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
        return 0;
    }
    calc(1);
    for(int i=2;i<=n;i++){
        calc(i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
    return 0;
}
/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1
*/