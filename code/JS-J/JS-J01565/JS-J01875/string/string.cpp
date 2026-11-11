#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+10;
int n;
int ans;
struct node{
    int cnt;
    char ch;
}arr[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].cnt>>arr[i].ch;
    }
    int l=1,r=n;
    int ll=arr[1].cnt,rr=arr[n].cnt;
    while(l<=n && r>=1 && l<r){
        if(ll==rr){
            if(arr[l].ch!=arr[r].ch){
                ans+=ll;
            }
            l++; r--;
            if(l<=n && r>=1){
                ll=arr[l].cnt; rr=arr[r].cnt;
            }
        }
        else if(ll<rr){
            int rem=rr-ll;
            if(arr[l].ch!=arr[r].ch){
                ans+=ll;
            }
            l++;
            if(l<=n && r>=1){
                ll=arr[l].cnt;
            }
            rr=rem;
        }
        else if(ll>rr){
            int rem=ll-rr;
            if(arr[l].ch!=arr[r].ch){
                ans+=rr;
            }
            r--;
            if(l<=n && r>=1){
                rr=arr[r].cnt;
            }
            ll=rem;
        }
    }cout<<ans<<'\n';
    return 0;
}
/*
RP++
8:57 need duipai
10:22 duipai finished ac
*/
