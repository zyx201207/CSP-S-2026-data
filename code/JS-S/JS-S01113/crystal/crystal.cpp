#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll a[N];
ll b[N];
ll n,m;
ll sum = 0;
ll max_ans = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll p = 0;
    ll st = 1;
    ll ed = 1;
    b[1] = a[1];
    for(int i=2;i<=n;i++){
        if((p+(a[i]-b[ed])*(ed-st+1))<=m){
            p+=(a[i]-b[ed])*(ed-st+1);
            ed++;
            b[ed] = a[i];
        }
        else{
            max_ans = max(ed-st+1,max_ans);
            while((p+(a[i]-b[ed])*(ed-st+1))>m && ed>st){
                p-=b[ed]-b[st];
                st ++;
            }
            p+=(a[i]-b[ed])*(ed-st+1);
            ed++;
            b[ed] = a[i];
        }
    }
    cout<<max_ans;
}
