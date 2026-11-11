#include<bits/stdc++.h>
using ll=long long;
#define pii pair<ll,int>
using namespace std;
int n;
char lst2,c;
ll ans,lst1,a;
deque<pii>q;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>lst1>>lst2;
    for(int i=2;i<=n;++i){
        cin>>a>>c;
        if(lst2==c)lst1+=a;
        else q.push_back({lst1,(int)(lst2-'a')}),lst1=a,lst2=c;
    }
    q.push_back({lst1,(int)(lst2-'a')});
    while(q.size()>=2){
        auto[a1,c1]=q.front();
        auto[a2,c2]=q.back();
        q.pop_front();q.pop_back();
        ll num=min(a1,a2);
        a1-=num;a2-=num;
        ans+=1LL*(c1!=c2)*num;
        if(a1)q.push_front({a1,c1});
        if(a2)q.push_back({a2,c2});
    }
    cout<<ans;
    return 0;
}
