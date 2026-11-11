#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],t[N],cnt[N];
stack<ll>stk,stk1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll l=0;
    for(ll i=n;i>=1;i--){
        memset(cnt,0,sizeof cnt);
        for(int j=n;j>=i;j--){
            stk.push(a[j]);
            cnt[a[j]]++;
        }
        while(cnt[a[i]]>1){
            ll num=a[i];
            while(stk.top()!=num){
                if(stk.top()==num)break;
                cnt[stk.top()]--;
                stk.pop();
            }
        }
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            t[stk.top()]++;
            stk.pop();
        }
        cout<<'\n';
    }
    for(ll i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
