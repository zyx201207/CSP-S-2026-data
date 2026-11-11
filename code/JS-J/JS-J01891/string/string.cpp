#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int> cnt(n);
    vector<char> ch(n);
    long long left=0,right=0,rp=0,lidx=0,ridx=n-1,ll=0,rl=0;
    for(int i=1;i<=n;++i){
        cin>>cnt[i-1]>>ch[i-1];
        right+=cnt[i-1];
    }
    rl=right;
    while(left<right){
        if(left>=ll+cnt[lidx]){
            ll+=cnt[lidx++];
        }
        if(right<=rl-cnt[ridx]){
            rl-=cnt[ridx--];
        }
        int mn=min(ll+cnt[lidx]-left,right-(rl-cnt[ridx]));
        if(ch[lidx]!=ch[ridx]){
            rp+=mn;
        }
        left+=mn; right-=mn;
    }
    cout<<rp;
    return 0;
}
