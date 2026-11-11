#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;

struct node{
    ll tot;
    char ch;
}s[N];

ll n,ans,cnt;
bool flag;

void pre(ll last,ll cost){
    while(cost){
        last--;
        if(cost>s[last].tot){
            s[last].tot=0;
            cost-=s[last].tot;
        }
        else{
            s[last].tot-=cost;
            cost=0;
        }
    }
}

void suf(ll nxt,ll cost){
    while(cost){
        nxt++;
        if(cost>s[nxt].tot){
            s[nxt].tot=0;
            cost-=s[nxt].tot;
        }
        else{
            s[nxt].tot-=cost;
            cost=0;
        }
    }

}


int main(){

    freopen("string.in","r",stdin);
    freopen("string .out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        ll a;
        char ch;
        cin>>a>>ch;
        if(ch==s[cnt].ch) s[cnt].tot+=a;
        else {
            cnt++;
            s[cnt].ch=ch;
            s[cnt].tot=a;
        }
    }

    if(cnt%2==0) flag=1;

    for(int i=1;i<=cnt/2;i++){
        ll pos1=i,pos2=cnt-i+1;
        if(pos1==cnt/2&&flag){
            ans+=min(s[pos1].tot,s[pos2].tot);
            continue;
        }
        if(s[pos1].ch==s[pos2].ch){
            if(s[pos1].tot==s[pos2].tot) continue;
            else {
                ll cost=abs(s[pos1].tot-s[pos2].tot);
                ans+=cost;
                if(s[pos1].tot>s[pos2].tot) pre(pos2,cost);
                else suf(pos1,cost);
            }
        }
        else {
            if(s[pos1].tot==s[pos2].tot) ans+=s[pos1].tot;
            else {
                if(s[pos1].tot>s[pos2].tot){
                    ans+=s[pos1].tot;
                    ll cost=s[pos1].tot-s[pos2].tot;
                    pre(pos2,cost);
                }
                else {
                    ans+=s[pos2].tot;
                    ll cost=s[pos2].tot-s[pos1].tot;
                    suf(pos1,cost);
                }
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}
