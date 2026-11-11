#include<bits/stdc++.h>
using namespace std;
const int MAX=2*1e5+10;
typedef long long ll;
struct pr{
    ll end;
};
pr e[MAX];
ll cnt,ans;
int n;r
vector<char> f;
ll find(ll u){
    int i=1;
    ll nums=0;
    while(nums<u){
        nums=e[i++].end;
    }
    return i-1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        char ch;
        cin>>a>>ch;
        f.push_back(ch);
        e[i].end=cnt+a;
        cnt+=a;
    }
    for(ll i=1;i<=cnt/2;i++){
        if(f[find(i)-1]!=f[find(cnt+1-i)-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

