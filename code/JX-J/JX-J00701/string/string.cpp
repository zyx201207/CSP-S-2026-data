#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans,t1;
int n;
deque<pair<ll,char>> q;
char tmp;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t1>>tmp;
        q.push_back({t1,tmp});
    }
    while(!q.empty()){
        pair<ll,char> f=q.front();
        pair<ll,char> b=q.back();
        q.pop_back();
        if(!q.empty()) q.pop_front();
        ll tp=abs(f.first-b.first);
        if(f.second==b.second){
            if(tp!=0LL){
                if(f.first>b.first) q.push_front({tp,f.second});
                if(f.first<b.first) q.push_back({tp,b.second});
            }
        }else{
            if(tp==0LL) ans+=f.first;
            else{
                if(f.first>b.first) {
                    ans+=b.first;
                    q.push_front({tp,f.second});
                }
                if(f.first<b.first) {
                    ans+=f.first;
                    q.push_back({tp,b.second});
                }
            }

        }
    }

    cout<<ans;

    return 0;
}







