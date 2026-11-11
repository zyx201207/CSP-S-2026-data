#include<bits/stdc++.h>
using namespace std;
long long n;pair<long long,char> s[100010];
long long ans=0;
long long p_idx=0,n_idx;
long long ta=0;
void solve(long long wsc,int pon){
    if(p_idx>n_idx) return;
    if(pon==1){
        s[p_idx].first-=wsc;
    }
    else if(pon==2){
        s[n_idx].first-=wsc;
    }long long a=s[p_idx].first-s[n_idx].first;
    if(s[p_idx].second!=s[n_idx].second){
        ans+=(a>0?s[n_idx].first:s[p_idx].first);
    }
    if(a>0){
        n_idx--;solve(s[n_idx+1].first,1);
    }
    if(a<0){
        p_idx++;solve(s[p_idx+1].first,2);
    }
    if(a==0){
        p_idx++;n_idx--;solve(0,0);
    }
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    n_idx=n-1;
    for(long long i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    solve(0,0);
    cout<<ans;
    return 0;
}
