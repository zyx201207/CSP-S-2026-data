#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    deque<pair<ll,string>> dq;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll cnt;
        string str;
        cin>>cnt>>str;
        /*if(str==dq.back().second&&!dq.empty()){
             ll num=dq.back().first;
             dq.pop_back();
             ll s=cnt+num;
             dq.push_back({s,str});
        }
        else*/dq.push_back({cnt,str});
    }
    while(!dq.empty()){
        ll fc=dq.front().first;
        string fs=dq.front().second;
        ll bc=dq.back().first;
        string bs=dq.back().second;
        dq.pop_front();
        dq.pop_back();
        if(fs==bs){
            if(fc>bc){
                ll cc=fc-bc;
                dq.push_front({cc,fs});
            }
            else if(fc<bc){
                ll cc=bc-fc;
                dq.push_back({cc,fs});
            }
        }
        else{
            if(fc>bc){
                ll cc=fc-bc;
                ans+=bc;
                dq.push_front({cc,fs});
            }
            else if(fc<bc){
                ll cc=bc-fc;
                ans+=fc;
                dq.push_back({cc,bs});
            }
            else{
                ans+=fc;
            }
        }
        if(dq.size()==1){
            break;
        }
    }
    cout<<ans;
    return 0;
}
